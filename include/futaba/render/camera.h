//
// Created by okn-yu on 2022/07/25.
//

#ifndef PRACTICEPATHTRACING_CAMERA_H
#define PRACTICEPATHTRACING_CAMERA_H

#include "futaba/core/ray.h"
#include "futaba/core/vec3.h"

class Camera {
public:
    Point3 cam_sensor_pos;
    Vec3 cam_sight_vec;
    Vec3 cam_side_vec;
    Vec3 cam_up_vec;
    float cam_sensor_height;
    float cam_sensor_width;
    float cam_sensor_dist;

    Camera(const Point3 &_cam_sensor_pos, const Vec3 &_cam_sight_vec, float _cam_sensor_width, float _cam_sensor_height,
           float _cam_sensor_dist);

    /*
     * (u, v)はセンサ上のワールド座標系で表された任意の座標を、cam_right_vecおよびcam_up_vecを基底として表現したときの係数に相当する
     * 例:
     *  ワールド座標系で(1, -1, 0)のセンサー右下の点の場合
     *  cam_right_vecが(-1, 0, 0), cam_up_vecが(0, 1, 0)の場合であれば、(u, v) = (-1, -1)として与えられる
     */

    /*
     * virtualは仮想関数でポリモーフィズムの実現に利用される
     * const = 0; は仮想関数を記載する際のお約束
     */

    virtual Ray shoot(float u, float v) const = 0;

private:

    /*
     * rot_x_angle, rot_y_angle関数
     * x軸->y軸の順で回転操作を実施したと過程した場合に、(0, 0, 1)がcam_sight_vecと一致するような回転角を求める
     */
    float _rot_x_angle() const;

    float _rot_y_angle() const;
};

class PinholeCamera : public Camera {
public:

    PinholeCamera(const Point3 &_cam_sensor_pos, const Vec3 &_cam_sight_vec, float _cam_sensor_width,
                  float _cam_sensor_height, float _cam_sensor_dist);

    Ray shoot(float u, float v) const override;
};

#endif //PRACTICEPATHTRACING_CAMERA_H
