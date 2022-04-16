//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST(T1,t){
	WeatherMock wm;
	ASSERT_ANY_THROW(wm.GetResponseForCity("Yerevan", {}));
	ASSERT_EQ(wm.GetResponseForCity("TANZANIA", {}),wm.GetResponseForCity("albania", {}));
	
}

TEST(T2,t){
	WeatherMock wm;
	ASSERT_ANY_THROW(wm.GetTemperature("T"));

}
TEST(T3,t){
	WeatherMock wm;
	Weather w;
	ASSERT_ANY_THROW(wm.GetTemperature("T"));
	ASSERT_ANY_THROW(wm.GetTomorrowTemperature("T"));
	ASSERT_ANY_THROW(wm.FindDiffBetweenTwoCities("T1", "T2"));
	ASSERT_ANY_THROW(ASSERT_NE(w.GetTomorrowDiff("Moscow"),""));

}
