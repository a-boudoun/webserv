/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Values.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:44:48 by mazhari           #+#    #+#             */
/*   Updated: 2023/03/09 17:28:51 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETVALUES_HPP
# define SETVALUES_HPP

# include "configFileParser.hpp"


class Values{
	protected:
		int							        _clientMaxBodySize;
		std::string							_autoIndex;
		std::string                         _host;
		std::string							_root;
		std::string							_serverName;
		std::vector<int>					_ports;
		std::map<int, std::string>			_errorPages;
		std::vector<std::string>			_allowMethods;
		std::vector<std::string>			_indexs;
	public:
		Values();
		virtual ~Values();
		virtual void    setValues(std::string &key, std::string &value) = 0;

		void setClientMaxBodySize(std::string key, std::string &value);
		void setAutoIndex(std::string key, std::string &value);
		void setHost(std::string key, std::string &value);
		void setRoot(std::string key, std::string &value);
		void setServerName(std::string key, std::string &value);
		void setPorts(std::string key, std::string &value);
		void setErrorPages(std::string key, std::string &value);
		void setAllowMethods(std::string key, std::string &value);
		void setIndexs(std::string key, std::string &value);
};

#endif