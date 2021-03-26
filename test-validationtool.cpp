#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

TEST_CASE("reports error when soc jumps abruptly") {
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 0);
}

TEST_CASE("reports Success  if no jumps in SOC Reading") {
  double socReadings[] = {0.0, 0.01, 0.03, 0.04};
  int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
  REQUIRE(validateSOCreadings(socReadings, numOfSocReadings) == 1);
}

TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings) == 0);
}

TEST_CASE("reports Success  if no jumps in Current Reading") {
  double currentReadings[] = {0.0, 0.01, 0.015, 0.02};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateCurrentreadings(currentReadings, numOfCurReadings) == 1);
}

TEST_CASE("reports error when Current reading with NULL value") {
  REQUIRE(validateCurrentreadings(0, 0) == 0);
}

TEST_CASE("reports error when soc reading with NULL value") {
  REQUIRE(validateSOCreadings(0, 0) == 0);
}


