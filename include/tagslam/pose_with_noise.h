/* -*-c++-*--------------------------------------------------------------------
 * 2019 Bernd Pfrommer bernd.pfrommer@gmail.com
 */

#pragma once

#include "tagslam/geometry.h"
#include "tagslam/pose_noise2.h"

namespace tagslam {
  class PoseWithNoise {
  public:
    PoseWithNoise(const Transform &tf = Transform(),
                  const PoseNoise2 &n = PoseNoise2(),
                  bool isVal = false) :
      pose(tf), noise(n), valid(isVal) {
    };
    const Transform  &getPose()  const { return (pose); }
    const PoseNoise2 &getNoise() const { return (noise); }
    bool              isValid()  const { return (valid); }
  private:
    Transform  pose;
    PoseNoise2 noise;
    bool       valid{false};
  };
  std::ostream &operator<<(std::ostream &os, const PoseWithNoise &pe);
}
