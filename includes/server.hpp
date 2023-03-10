/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazhari <mazhari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:15:21 by mazhari           #+#    #+#             */
/*   Updated: 2023/03/10 16:07:49 by mazhari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include "configFileParser.hpp"
#include "location.hpp"
#include "Values.hpp"

class server: public Values
{
	private:
		std::map<std::string, location>		_locations;
		// request								_request;
		// response							_response;
		// client
	public:
		server(parsConfig &config);
		~server();

		void setValues(std::string &key, std::string &value);
		void setDefaultValues();
		// execPost();
		// execGET();
		// execDELEt();
		// startserver();

		void printValues();
};

#endif