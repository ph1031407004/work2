/****************************
已知相机的位姿用四元数表示为q=[0.35,0.2,0.3,0.1],顺序为x,y,z,w，请编程实现：

输出四元数对应的旋转矩阵、旋转矩阵的转置，旋转矩阵的逆矩阵，旋转矩阵乘以自身的转置，验证旋转矩阵的正交性。

 ****************************/
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
using namespace Eigen;

int main(int argc, char **argv)
{
	Eigen::Quaterniond quat = Quaterniond(0.1, 0.35, 0.2, 0.3);
	// quat = quat.Identity();
	quat.normalize();

	// 旋转矩阵
	Eigen::Matrix3d rotation_matrix = quat.toRotationMatrix();
	cout << "rotation_matrix" << endl;
	cout << rotation_matrix << endl;
	// 旋转矩阵的转置
	Eigen::Matrix3d rotation_matrix_T = rotation_matrix.transpose();
	cout << "rotation_matrix^T" << endl;
	cout << rotation_matrix_T << endl;
	// 旋转矩阵的逆
	Eigen::Matrix3d rotation_matrix_INV = rotation_matrix.inverse();
	cout << "rotation_matrix^-1" << endl;
	cout << rotation_matrix_INV << endl;

	Eigen::Matrix3d result = rotation_matrix * rotation_matrix_T;
	cout << "result" << endl;
	cout << result << endl;
	return 0;
}
