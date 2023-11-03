# Http-Webserver-in-C++
Overall, this web server is a basic implementation for educational purposes and lacks several advanced features found in production-ready web servers, such as support for multiple threads or processes, security measures, and robust error handling. It serves as a simple example of how a web server can handle HTTP requests and responses in C++.
Resource Lookup Behavior
The server searches for index.html when no resource name is present in the request.
If index.html is absent, the server searches for index.htm.
If both index.html and index.htm are absent, the server sends a custom 404 error page.
