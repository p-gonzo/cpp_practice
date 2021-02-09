#include <iostream>
#include <cpprest/http_client.h>

std::pair<std::string, int> getApi()
{

    web::http::client::http_client_config cfg; 
    cfg.set_timeout(std::chrono::milliseconds(10));
    web::http::client::http_client client(U("http:/912.168.1.219:8080"), cfg);
    web::http::http_request req(web::http::methods::GET);
    auto uri = web::http::uri_builder("/some/path/here");
    uri.append_query("key", "val", true);
    uri.append_query("otherkey", "othervale", true);
    req.set_request_uri(uri.to_uri());
    req.headers().add("X-API-Key", "Some Key");

    bool success;
    std::string result;
    
    auto requestTask = client.request(req)
        .then([&success, &result](const web::http::http_response& response)
        {
            success = response.status_code() == 200;
            
            Concurrency::streams::stringstreambuf buffer;
            response.body().read_to_end(buffer).get();
            result = buffer.collection().c_str();
            
        });
    try
    {
        requestTask.wait();
    }
    catch (const std::exception &e)
    {
        success = false;
        result = e.what();
    }
    return std::make_pair(result, success);
}
int main()
{
    auto res = getApi();
    std::cout << res.first << std::endl;
    std::cout << res.second << std::endl;
    return 0;
}