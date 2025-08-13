clc ;
close all
clear all ;
%%%%%%%%%%%%%%%
L=48e-6 ;
k=-1/3;
M=  L*k 
%N=4 %number of turns
rL=8.05e-3;
V_fc=14.4;
C=100e-6;
r_load=5;

%--noyau type 56/24/19
Ae=337e-6; %effective area
Le=107e-3; %effective length
AL=5200e-9;
ur=1320;
Ae_outerleg=Ae/2;
B_sat=0.52;
Airgap=0.65e-3;
N=14; %nbre de spires
rL=10e-3;