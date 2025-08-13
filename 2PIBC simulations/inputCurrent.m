% clear plot
% clear figure
% 
% iL_in = out.iL_in.signals.values  ;
% t      = out.tout;
% 
% figure('Name','Test','NumberTitle','off');
% 
% plot(t, iL_in, 'LineWidth',1.5);
% grid on;
% 
% title('UnCoupled Inductor input Current iL_{in}');
% xlabel('Time (s)');
% ylabel('Current (A)');
% 
% %xlim([0.37640 0.37644]);  % zoom in on interval
% 
% % Add a legend
% legend('iL_{in}');

iL_in = out.iL_in.signals.values;
t      = out.tout;

figure('Name','Test','NumberTitle','off');

% --- Main axes ---
axMain = axes;                         % automatically fills the figure
plot(axMain, t, iL_in, 'LineWidth',2);
grid(axMain,'on');
title(axMain,'Directly Coupled Inductor Input Current iL_{in}');
xlabel(axMain,'Time (s)');
ylabel(axMain,'Current (A)');
legend(axMain,'iL_{in}');

% ----- Ripple label ----------------------------------------------------
text(axMain, 0.05, 0.90, 'Current ripple = 12 %', ... % x,y in normalized units
     'Units','normalized', ...
     'FontSize',12, ...
     'FontWeight','bold', ...
     'BackgroundColor','white', ...
     'Margin',4);       % small padding around the text
% -----------------------------------------------------------------------

% --- Inset (zoom) axes ---
axZoom = axes('Position',[0.60 0.55 0.30 0.30]);   % [x y w h] in normalized units
plot(axZoom, t, iL_in, 'LineWidth',1.5);
grid(axZoom,'on');
xlim(axZoom,[0.37640 0.37644]);
title(axZoom,'Zoom');
set(axZoom,'Box','on');                % draws a border so it stands out


