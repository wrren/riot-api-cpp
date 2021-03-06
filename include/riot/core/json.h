#ifndef RIOT_JSON_H
#define RIOT_JSON_H

#include <rapidjson/document.h>

namespace riot
{
	/**
	 *	Represents a response to a HTTP request that contains JSON data
	 */
	class json
	{
	public:

		/**
		 *	Available Status Codes
		 */
		enum status
		{
			PENDING			= 0,
			OK			= 200,
			OK_CREATED		= 201,
			OK_ACCEPTED		= 202,
			CLIENT_ERROR		= 400,
			CLIENT_UNAUTHORIZED	= 401,
			CLIENT_FORBIDDEN	= 403,
			CLIENT_NOT_FOUND	= 404,
			CLIENT_RATE_LIMITED	= 429,
			SERVER_ERROR		= 500,
			SERVER_UNAVAILABLE	= 503
		};

		/**
		 *	Construct a JSON response with the specified status code
		 * @param status 	HTTP status code
		 */
		json( int status );

		/**
		 *	Indicates whether the server response was successfully received and parsed. 
		 *	If ok() return false, but the status code is 200 OK, this indicates that a parse
		 *	error has occurred.
		 * @return 	true - If the server response was successfully received
		 *		and parsed, false otherwise.
		 */
		bool ok() const;

		/**
		 *	Get the HTTP response status code
		 * @return 	Status Code
		 */
		int status() const;

		/**
		 *	Parse the provided response body
		 * @param response 	Request response body
		 */
		void parse( const std::string& response );

		/// JSON Document Accessor
		const rapidjson::Document& document() const;

	private:

		
		/// Status Code
		int m_status;
		/// JSON Document
		rapidjson::Document m_document;
	};
}

#endif // RIOT_JSON_H