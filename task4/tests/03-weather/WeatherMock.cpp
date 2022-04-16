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
        
        if(city == ""){
        	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\"main\": { \n \"temp\" : \"30\"} , \"list\" : {\n \"7\" :  { \n\"main\":  {\"temp\": \"30\"}}}}";
         	return r;
        }
        
        if(city == "T"){
         	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\"main\": { \n \"temp\" : 30}}";
         	return r;
         }
         if(city == "T1"){
         	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\"main\": { \n \"temp\" : 32}}";
         	return r;
         }
         if(city == "T2"){
         	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\"main\": { \n \"temp\" : 33}}";
         	return r;
         }
         if(city == "4"){
         	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\n\"main\": {\n \"temp\": 30},\n \"list\": {\n \"7\" : {\n\"main\" : {\n \"temp\" : 34}}}}";
         	return r;
         }
         if(city == "2"){
         	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\n\"main\": {\n \"temp\": 30},\n \"list\": {\n \"7\" : {\n\"main\" : {\n \"temp\" : 32}}}}";
         	return r;
         }
         if(city == "-2"){
         	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\n\"main\": {\n \"temp\": 32},\n \"list\": {\n \"7\" : {\n\"main\" : {\n \"temp\" : 30}}}}";
         	return r;
         }
         if(city == "-4"){
         	cpr::Response r;
         	r.status_code = 200;
         	r.text = "{\n\"main\": {\n \"temp\": 36},\n \"list\": {\n \"7\" : {\n\"main\" : {\n \"temp\" : 32}}}}";
         	return r;
         }
       	cpr::Response r;
      	r.status_code = 200;
        r.text = "{\n\"main\": {\n \"temp\": 30},\n \"list\": {\n \"7\" : {\n\"main\" : {\n \"temp\" : 30}}}}";
        return r;
}
