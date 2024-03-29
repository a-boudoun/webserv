/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgi.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:11:58 by mazhari           #+#    #+#             */
/*   Updated: 2023/04/05 19:52:36 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.hpp"

void    response::cgi(ParseRequest& req){
	std::string 	output;
	int				status = 0;
 
	this->setCgiCmd();
	this->setCgiEnv(req);

	char        **env = stringToChar(this->_env);
	char        **cmd = stringToChar(this->_cmd);

	int tmp = dup(0);
	int fd[2];

	if (pipe(fd) < 0){
		this->setStatus(502);
		return ;
	}
	pid_t pid = fork();
	if (pid < 0){
		this->setStatus(502);
		return ;
	}

	if (pid == 0){
		dup2(fd[1], 1);
		close(fd[1]);

		std::FILE *tmp;
		tmp = tmpfile();
		
    	if (tmp) {
			std::string str = req.getBody();
        	std::fprintf(tmp, "%s", str.c_str());
        	std::rewind(tmp);
    	}

		dup2(fileno(tmp), 0);
		std::fclose(tmp);

		if (chdir(this->_location.getRoot().c_str()) < 0)
			exit(1);
		alarm(CGI_TIMEOUT);
		if (execve(cmd[0], cmd, env) == -1)
			exit(1);
	}
	waitpid(pid, &status, 0);

	if (WIFSIGNALED(status) || status != 0) {
			this->setStatus(502);
		return ;
	}

	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);

	char buf[1];
	while (read(0, buf, 1) > 0)
	   output.append(buf, 1);

	dup2(tmp, 0);
	close(tmp);

	delete [] env;
	delete [] cmd;
	this->parseCgiOutput(output);
}

void	response::setCgiEnv(ParseRequest& req){
	this->_env.push_back("SERVER_SOFTWARE=webserv/1.0");
	this->_env.push_back("SERVER_NAME=" + this->_location.getServerName());
	this->_env.push_back("GATEWAY_INTERFACE=CGI/1.1");
	this->_env.push_back("SERVER_PROTOCOL=HTTP/1.1");
	this->_env.push_back("SERVER_PORT= " + req.getPort());
	this->_env.push_back("REQUEST_METHOD=" + req.getMethod());
	this->_env.push_back("CONTENT_TYPE=" + req.getHeadr("Content-Type"));
	this->_env.push_back("CONTENT_LENGTH=" + toStr(req.getBody().size()));
	this->_env.push_back("QUERY_STRING=" + req.getQuery());
	this->_env.push_back("REDIRECT_STATUS=200");
	this->_env.push_back("DOCUMENT_ROOT=" + this->_location.getRoot());
	this->_env.push_back("SCRIPT_FILENAME=" + this->_cmd[1]);
	this->_env.push_back("HTTP_COOKIE=" + req.getHeadr("Cookie"));
}

void   response::setCgiCmd(){
	std::string extension = "." + getExtension(this->_filePath);
	std::string cgiPath = this->_location.getCgiPaths()[extension];

	std::string file = this->_filePath.substr(this->_filePath.find_last_of("/") + 1);

	this->_cmd.push_back(cgiPath);
	this->_cmd.push_back(file);
}

char **response::stringToChar(std::vector<std::string> &vec)
{
	int i = 0;
	char **arry = new char *[vec.size() + 1];
	for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); it++)
		arry[i++] = (char *)(*it).c_str();
	arry[i] = NULL;
	return (arry);
}

void    response::parseCgiOutput(std::string output){
	std::istringstream  tmp(output);
	std::string         line;
	std::string 		key;

	while (std::getline(tmp, line)){
		line += "\n";

		size_t pos = line.find(":");
		if (pos != std::string::npos){
			key = line.substr(0, pos);

			if (key == "Set-Cookie")
				this->_cookies.push_back(line.substr(pos + 1, line.find("\r\n") - pos - 1));
			else
				this->setHeader(key, line.substr(pos + 1, line.find("\r\n") - pos - 1));
		}
		else if (line.find("\r\n") != std::string::npos){
			break;
		}
	}
	getline(tmp, this->_body, '\0');
	if (!this->_body.empty())
		this->setStatus(200);
	else
		this->setStatus(502);
}

bool  response::isCgi(std::string file){
	std::map<std::string, std::string> 	extensions = this->_location.getCgiPaths();
	std::string							extension = "." + getExtension(file);
	
	if (this->_location.getCgiPaths().empty())
		return false;
	if (extensions.find(extension) == extensions.end())
		return false;
	return true;
}