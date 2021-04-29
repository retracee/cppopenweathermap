#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

std::string
url = "PUT API URL HERE";
namespace 
{
    std::size_t callback(
            const char* in,
            std::size_t size,
            std::size_t num,
            std::string* out)
    {
        const std::size_t totalBytes(size * num);
        out->append(in, totalBytes);
        return totalBytes;
    }
}


int main(void){
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    long httpCode(0);
    std::unique_ptr<std::string> httpData(new std::string());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());
    curl_easy_perform(curl);
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
    curl_easy_cleanup(curl);
        if (httpCode == 200){       
            using json = nlohmann::json; 
            json j = json::parse(*httpData.get());
            std::string status1 = j["weather"][0]["main"].dump(); status1.erase(0,1); status1.erase(status1.end()-1);
            int temperatures1 = j["main"]["temp"];
            std::string iconf, icon = j["weather"][0]["icon"].dump(); icon.erase(0,1); icon.erase(icon.end()-1);
            if (icon == "01d"){
                iconf = "";
            } else if (icon == "02d"){
                iconf = "";
            } else if (icon == "03d"){
               iconf = "";
            } else if (icon == "04d"){
                iconf = "";
            } else if (icon == "09d"){
                iconf = "";
            } else if (icon == "10d"){
                iconf = "";
            } else if (icon == "11d"){
                iconf = "";
            } else if (icon == "13d"){
                iconf = "";
            } else if (icon == "50d"){
                iconf = "";
            } else if (icon == "01n"){
                iconf = "";
            } else if (icon == "02n"){
                iconf = "";
            } else if (icon == "03n"){
                iconf = "";
            } else if (icon == "04n"){
                iconf = "";
            } else if (icon == "09n"){
                iconf = "";
            } else if (icon == "10n"){
                iconf = "";
            } else if (icon == "11n"){
                iconf = "";
            } else if (icon == "13n"){
                iconf = "";
            } else if (icon == "50n"){
                iconf = "";
            }


            std::cout << iconf << " " << status1 <<  " " << temperatures1 << "°F" << std::endl;
        }
        else{
            std::cout << "NO CONNECTION" << std::endl;
        }
}

