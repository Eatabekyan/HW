//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"
	
cpr::Response WeatherMock::Get(const std::string& city, const cpr::Url& url) {
        if(city == "Yerevan"){
            cpr::Response r;
            r.status_code = 20;
            r.text = "{}";
            return r;
        }
         cpr::Response r;
         r.status_code = 200;
         r.text = "{}";
        return r;
}
