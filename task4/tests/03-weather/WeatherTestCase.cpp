//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(T1,t){
	WeatherMock wm;
	ASSERT_ANY_THROW(wm.GetResponseForCity("Yerevan", {}));
	ASSERT_EQ(wm.GetResponseForCity("", {}),wm.GetResponseForCity("", {}));
	
}

TEST(T2,t){
	WeatherMock wm;
	ASSERT_EQ(wm.GetTemperature("T"), 30.0);

}
TEST(T3,t){
	WeatherMock wm;
	wm.SetApiKey("Moscow");
	ASSERT_EQ(wm.GetTomorrowTemperature("Moscow"), 30.0);
	

}


TEST(T6,t){
	WeatherMock wm;
	wm.SetApiKey("Moscow");
	
	ASSERT_EQ(wm.FindDiffBetweenTwoCities("T", "T"),0.0);
	wm.GetDifferenceString("T1", "T2");
	wm.GetDifferenceString("T2", "T1");

}
TEST(T7,t){
	WeatherMock wm;
	wm.SetApiKey("Moscow");
	
	wm.GetTomorrowDiff("Moscow");
	wm.GetTomorrowDiff("2");
	wm.GetTomorrowDiff("-2");
	wm.GetTomorrowDiff("4");
	wm.GetTomorrowDiff("-4");

}
