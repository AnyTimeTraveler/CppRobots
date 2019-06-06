/**
*   \copyright Copyright 2016 Hochschule Emden/Leer. This project is released
* under
* the MIT License, see the file
* LICENSE.md for rights and limitations.
*   \file Hunter.cpp
*   \author Jan-Niklas Braak
*/
#include <cmath>
#include <iostream>

#include "Agents/Simon.hpp"
#include "Angles.hpp"
#include "mathUtility.hpp"

Simon::Simon(double targetDistance, double K_perp, double K_straight)
  : targetDistance(targetDistance), K_perp(K_perp), K_straight(K_straight) {}

Action Simon::update(Robot const &r) {
  const auto target_robot = r.scanClosest();
  const auto position = r.getPosition();
  const auto rotation = r.getRotation();

  double turret_angle;
  Vector_d delta_position;

  const auto target_position = r.rules.arena_size / 2.0;
  delta_position = target_position - position;
  turret_angle = r.getTurretAngle() + r.rules.scan_angle;

  return {r.rules.v_max /4, turn_toward(delta_position.angle(), rotation), turret_angle, true};
}

double Simon::turn_toward(double angle, double rotation) const {
  const auto straight_error = angDiffRadians(angle, rotation);
  const auto w = straight_error * K_straight;

  return w;
}
