/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postMethod.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudoun <aboudoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:38:20 by aboudoun          #+#    #+#             */
/*   Updated: 2023/03/29 00:45:56 by aboudoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "response.hpp"

void response::Post(server& serv, ParseRequest& request)
{
	(void)request;
	(void)serv;
	// std::string path;

	// path = this->getLocation().getRoot();
	// path = joinPaths(path, fixLink(request.getLink().substr(this->getLocationPath().size())));
	
	// if (this->getLocation().getUpload() && this->getLocation().getUpload() == "on")
	// {
	// 	if ()
	// 	{
	// 		this->setUpload(true);
	// 		this->setFilePath(path);
	// 		return;	
	// 	}
	// }
	// // if (/*hi*/)
	// // {
	// // 	std::ofstream file(path, std::ios::app);
	// // 	if (file.is_open())
	// // 		{
	// // 		file << request.getBody();
	// // 		file.close();
	// // 		this->setStatus("Created", 201);
	// // 		this->setFilePath(path);
	// // 		this->fillResponse(serv);
	// // 		}
	// // 	else
	// // 		{
	// // 			this->setStatus("Internal Server Error", 500);
	// // 			this->setFilePath("./error_pages/500.html");
	// // 			this->fillResponse(serv);
	// // 		}
	// // }
	// if (!is_file(path) && !is_dir(path))
	// {
	// 	this->setStatus(404);
	// 	this->setFilePath("./error_pages/404.html");
	// 	this->fillResponse(serv, "");
	// }
	// else if (is_dir(path))
	// {
	// 	if (this->getLocation().getIndexs().empty())
	// 	{
	// 		// TODO do i need to check if the index is present in the directory? or just pss it to the cgi?
	// 		this->setStatus(403);
	// 		this->setFilePath("./error_pages/403.html");
	// 		this->fillResponse(serv, "");
	// 	}
	// 	else if (this->getLocation().getCgiPaths().empty())
	// 	{
	// 		this->setStatus(403);
	// 		this->setFilePath("./error_pages/403.html");
	// 		this->fillResponse(serv, "");
	// 	}
	// 	else
	// 	{
	// 		//run cgi on requested file with Post method
	// 	}
	// }
	// else if (is_file(path))
	// {
	// 	if (this->getLocation().getCgiPaths().empty())
	// 	{
	// 		this->setStatus(403);
	// 		this->setFilePath("./error_pages/403.html");
	// 		this->fillResponse(serv, "");
	// 	}
	// 	else
	// 	{
	// 		//run cgi on requested file with Post method
	// 	}
	// }
}