
// ==============================================================================
// 
// Copyright or © or Copr:
//     Antoine Falaize
// 
// Affiliation:
//     Team M2N (Mathematical and Numerical Methods),
//     Laboratoire des Sciences de l'Ingénieur pour l'Environnement (LaSIE),
//     UMR CNRS 7356, La Rochelle Université,
//     La Rochelle, France.
// 
// Contact:
//     antoine.falaize@univ-lr.fr
// 
// This file has been generated by the Python software PyPHS, which purpose
// is to model and simulate multiphysical systems in the Port-Hamiltonian
// formalism. See the website at the following url:
// "https://pyphs.github.io/pyphs/".
// 
// Created on:
//     2020/07/08 10:56:10
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// A copy of the GNU General Public License is available at the following url:
// "https://www.gnu.org/licenses/"
// 
// ==============================================================================

#ifndef FPUT_H
#define FPUT_H

#include <iostream>
#include <vector>
#include <cmath>
#include <Eigen/Dense>
#include "parameters.h"

    // new include ++++
    #include <Eigen/SparseCholesky>
    #include <Eigen/Sparse>
    typedef Eigen::SparseMatrix<double> SpMat; 


using namespace std;
using namespace Eigen;

class FPUT {
//==========================================================================
// PUBLIC    
    public:
    //==========================================================================
    // Sample Rate
    void set_sampleRate(float &);
    void set_sampleRate(double &);
    //==========================================================================
    // Core update
    void update();
    //==========================================================================
    // Acessors to Arguments, return vector<double>
    const vector<double> & x_vector() const;
    const vector<double> & dx_vector() const;
    const vector<double> & w_vector() const;
    const vector<double> & u_vector() const;
    const vector<double> & p_vector() const;
    const vector<double> & vnl_vector() const;
    const vector<double> & o_vector() const;
    //==========================================================================
    // Acessors to Arguments, return Matrix<double, n, m>
    const Matrix<double,15, 1> & x() const;
    const Matrix<double,15, 1> & dx() const;
    const Matrix<double,0, 0> & w() const;
    const Matrix<double,0, 0> & u() const;
    const Matrix<double,0, 0> & p() const;
    const Matrix<double,15, 1> & vnl() const;
    const Matrix<double,12, 1> & o() const;
    //==========================================================================
    // Mutators for Arguments, type = vector<double>
    void set_x(const vector<double> &);
    void set_dx(const vector<double> &);
    void set_w(const vector<double> &);
    void set_u(const vector<double> &);
    void set_p(const vector<double> &);
    void set_vnl(const vector<double> &);
    void set_o(const vector<double> &);
    //==========================================================================
    // Mutators for Arguments, type = Matrix<double, n, m>
    void set_x(const Matrix<double, 15, 1> &);
    void set_dx(const Matrix<double, 15, 1> &);
    void set_w(const Matrix<double, 0, 0> &);
    void set_u(const Matrix<double, 0, 0> &);
    void set_p(const Matrix<double, 0, 0> &);
    void set_vnl(const Matrix<double, 15, 1> &);
    void set_o(const Matrix<double, 12, 1> &);
    //==========================================================================
    // Mutators for a single argument, types are double with int index
    void set_x(const double &, unsigned int &);
    void set_dx(const double &, unsigned int &);
    void set_w(const double &, unsigned int &);
    void set_u(const double &, unsigned int &);
    void set_p(const double &, unsigned int &);
    void set_vnl(const double &, unsigned int &);
    void set_o(const double &, unsigned int &);
    //==========================================================================
    // Functions Results Accessors (matrix)
    const Matrix<double,12, 1> & ud_o() const;
    const Matrix<double,15, 1> & Gnl() const;
    const Matrix<double,15, 15> & jacGnlnl() const;
    const Matrix<double,15, 1> & dxH() const;
    const Matrix<double,0, 0> & z() const;
    const Matrix<double,0, 0> & y() const;
    //==========================================================================
    // Functions Results Accessors (vector)
    const vector<double> & ud_o_vector() const;
    const vector<double> & Gnl_vector() const;
    const vector<double> & jacGnlnl_vector() const;
    const vector<double> & dxH_vector() const;
    const vector<double> & z_vector() const;
    const vector<double> & y_vector() const;
    //==========================================================================
    // Functions Results Accessors (element)
    const double & ud_o(unsigned int &) const;
    const double & Gnl(unsigned int &) const;
    const double & jacGnlnl(unsigned int &) const;
    const double & dxH(unsigned int &) const;
    const double & z(unsigned int &) const;
    const double & y(unsigned int &) const;
    //==========================================================================
    // Oprations Results Accessors
    const Matrix<double,15, 1> & ud_x() const;
    const Matrix<double,15, 1> & Fnl() const;
    const Matrix<double,15, 15> & jacFnl() const;
    const Matrix<double,15, 15> & ijacFnl() const;
    const Matrix<double,15, 1> & save_Fnl() const;
    const double & res_Fnl() const;
    const double & step_Fnl() const;
    const Matrix<double,15, 1> & ud_vnl() const;
    //==========================================================================
    // Oprations Results Accessors
    vector<double> ud_x_vector() const;
    vector<double> Fnl_vector() const;
    vector<double> save_Fnl_vector() const;
    vector<double> ud_vnl_vector() const;
    //==========================================================================
    // Default Constructor
    FPUT();
    //==========================================================================
    // Default Destructor
    ~FPUT();

//==========================================================================
// PRIVATE    
    private:
    //==========================================================================
    // Sample Rate
    double sampleRate = 10000.0;
    const double * F_S = & sampleRate;
    //==========================================================================
    // Parameters
    const unsigned int indexParameters = 0;  // See file "parameters.cpp".
    const double * m_L1 = & subs[indexParameters][0];
    const double * m_L2 = & subs[indexParameters][1];
    const double * m_L3 = & subs[indexParameters][2];
    const double * m_L4 = & subs[indexParameters][3];
    const double * m_L5 = & subs[indexParameters][4];
    const double * m_L6 = & subs[indexParameters][5];
    const double * m_L7 = & subs[indexParameters][6];
    const double * m_R1 = & subs[indexParameters][7];
    const double * m_R2 = & subs[indexParameters][8];
    const double * m_R3 = & subs[indexParameters][9];
    const double * m_R4 = & subs[indexParameters][10];
    const double * m_R5 = & subs[indexParameters][11];
    const double * m_R6 = & subs[indexParameters][12];
    const double * m_R7 = & subs[indexParameters][13];
    const double * k_1 = & subs[indexParameters][14];
    const double * k_2 = & subs[indexParameters][15];
    const double * k_3 = & subs[indexParameters][16];
    const double * k_4 = & subs[indexParameters][17];
    const double * k_5 = & subs[indexParameters][18];
    const double * k_6 = & subs[indexParameters][19];
    const double * k_7 = & subs[indexParameters][20];
    //==========================================================================
    // Arguments
    Matrix<double,42, 1> args;
    double * Pi_L1 = & args(0, 0);
    double * Pi_12 = & args(1, 0);
    double * Pi_23 = & args(2, 0);
    double * Pi_34 = & args(3, 0);
    double * Pi_45 = & args(4, 0);
    double * Pi_56 = & args(5, 0);
    double * Pi_67 = & args(6, 0);
    double * Pi_R7 = & args(7, 0);
    double * x_k1 = & args(8, 0);
    double * x_k2 = & args(9, 0);
    double * x_k3 = & args(10, 0);
    double * x_k4 = & args(11, 0);
    double * x_k5 = & args(12, 0);
    double * x_k6 = & args(13, 0);
    double * x_k7 = & args(14, 0);
    double * dPi_L1 = & args(15, 0);
    double * dPi_12 = & args(16, 0);
    double * dPi_23 = & args(17, 0);
    double * dPi_34 = & args(18, 0);
    double * dPi_45 = & args(19, 0);
    double * dPi_56 = & args(20, 0);
    double * dPi_67 = & args(21, 0);
    double * dPi_R7 = & args(22, 0);
    double * dx_k1 = & args(23, 0);
    double * dx_k2 = & args(24, 0);
    double * dx_k3 = & args(25, 0);
    double * dx_k4 = & args(26, 0);
    double * dx_k5 = & args(27, 0);
    double * dx_k6 = & args(28, 0);
    double * dx_k7 = & args(29, 0);
    double * RHS_1 = & args(30, 0);
    double * RHS_2 = & args(31, 0);
    double * RHS_3 = & args(32, 0);
    double * RHS_4 = & args(33, 0);
    double * RHS_5 = & args(34, 0);
    double * RHS_6 = & args(35, 0);
    double * Delta_12 = & args(36, 0);
    double * Delta_23 = & args(37, 0);
    double * Delta_34 = & args(38, 0);
    double * Delta_45 = & args(39, 0);
    double * Delta_56 = & args(40, 0);
    double * Delta_67 = & args(41, 0);
    //==========================================================================
    // Functions Results Definitions
    Matrix<double,12, 1> _ud_o;
    Matrix<double,15, 1> _Gnl;
    Matrix<double,15, 15> _jacGnlnl;
    Matrix<double,15, 1> _dxH;
    Matrix<double,0, 0> _z;
    Matrix<double,0, 0> _y;
    //==========================================================================
    // Functions Results Updates
    void ud_o_update();
    void Gnl_update();
    void jacGnlnl_update();
    void dxH_update();
    void z_update();
    void y_update();
    //==========================================================================
    // Operations Results Definition
    Matrix<double,15, 1> _ud_x;
    Matrix<double,15, 1> _Fnl;
    Matrix<double,15, 15> _jacFnl;
    Matrix<double,15, 15> _ijacFnl;
    Matrix<double,15, 1> _save_Fnl;
    double _res_Fnl;
    double _step_Fnl;
    Matrix<double,15, 1> _ud_vnl;
    //==========================================================================
    // Oprations Results Updates
    void ud_x_update();
    void Fnl_update();
    void jacFnl_update();
    void ijacFnl_update();
    void save_Fnl_update();
    void res_Fnl_update();
    void step_Fnl_update();
    void ud_vnl_update();
    //==========================================================================
    // Initialization
    void init();

        //==========================================================================
        // New functions for the LDL.T solve update
        SpMat A;
        void ud_o_init();
        void A_update();
        void A_init();
        void RHS_update();
        Matrix<double, 7, 1> delta;
        Matrix<double, 7, 1> RHS_vec;

        Eigen::ConjugateGradient<SparseMatrix<double>, 
                             Lower|Upper,
                             DiagonalPreconditioner<double>
                            > solver;
        };

#endif /* FPUT_H */
