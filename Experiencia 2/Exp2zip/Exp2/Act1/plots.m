%% plot sin 2,5 t10
% Cargar datos desde el archivo .mat
load('C:\Users\Rodrigo\Desktop\LAB CONTROL\ELO271_USM\Experiencia 2\Exp2zip\Exp2\Act1\SdPC1_T10.mat');

% Graficar y contra x
plot(data(1,:), data(2,:));

% Agregar etiquetas y título
xlabel('Tiempo');
ylabel('Voltaje');
title('Sinoidal frecuencia 0.1[Hz]');

% Mostrar la cuadrícula
grid on;

% Mostrar la leyenda si es necesario
%% plot sin 2,5 t1
% Cargar datos desde el archivo .mat
load('C:\Users\Rodrigo\Desktop\LAB CONTROL\ELO271_USM\Experiencia 2\Exp2zip\Exp2\Act1\SdPC1_T1.mat');

% Graficar y contra x
plot(data(1,:), data(2,:));

% Agregar etiquetas y título
xlabel('Tiempo');
ylabel('Voltaje');
title('Sinoidal frecuencia 1[Hz]');

% Mostrar la cuadrícula
grid on;

% Mostrar la leyenda si es necesario

%% plot sin 2,5 t0.01
% Cargar datos desde el archivo .mat
load('C:\Users\Rodrigo\Desktop\LAB CONTROL\ELO271_USM\Experiencia 2\Exp2zip\Exp2\Act1\SdPC1_T0_01.mat');

% Graficar y contra x
plot(data(1,:), data(2,:));

% Agregar etiquetas y título
xlabel('Tiempo');
ylabel('Voltaje');
title('Sinoidal frecuencia 100[Hz]');

% Mostrar la cuadrícula
grid on;

% Mostrar la leyenda si es necesario
