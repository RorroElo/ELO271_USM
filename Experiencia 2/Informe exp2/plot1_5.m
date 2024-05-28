%% plot sin tm 1e-3 write
% Cargar datos desde el archivo .mat
load('C:\Users\Rodrigo\Desktop\LAB CONTROL\ELO271_USM\Experiencia 2\Exp2zip\Exp2\Act1\SdPC1_5_st_10.mat');

% Graficar y contra x
plot(data(1,:), data(2,:));

% Agregar etiquetas y título
xlabel('Tiempo [s]');
ylabel('Voltaje [V]');
title('HIL Write Analog');

% Mostrar la cuadrícula
grid on;

% Mostrar la leyenda si es necesario
%% plot sin tm 1e-3 read
% Cargar datos desde el archivo .mat
load('C:\Users\Rodrigo\Desktop\LAB CONTROL\ELO271_USM\Experiencia 2\Exp2zip\Exp2\Act1\matlab.mat');

% Graficar y contra x
plot(data(1,:), data(2,:));

% Agregar etiquetas y título
xlabel('Tiempo[s]');
ylabel('Voltaje[V]');
title('HIL Read Analog');

% Mostrar la cuadrícula
grid on;

% Mostrar la leyenda si es necesario