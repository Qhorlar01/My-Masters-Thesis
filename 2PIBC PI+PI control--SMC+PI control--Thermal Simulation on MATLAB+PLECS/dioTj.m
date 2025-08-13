%% 1)  Pull the data out of the structure
diode = out.DiodeTemp;              % convenience alias
t     = diode.time;                 % common time vector

T_j_dio        = diode.signals(1).values;   % diode junction temperature
T_heatSink_dio = diode.signals(2).values;   % diode heat‑sink temperature
P_losses_dio   = diode.signals(3).values;   % diode power losses

%% 2)  Make the figure larger and increase font sizes / line widths
figure(2); clf
set(gcf,'Units','normalized','OuterPosition',[0 0 1 1]);   % full‑screen
set(groot,'defaultAxesFontSize',14);                       % bigger labels
set(groot,'defaultLineLineWidth',1.8);                     % thicker lines

tiledlayout(3,1,"TileSpacing","compact","Padding","compact")

% -- 1st subplot ----------------------------------------------------------
nexttile
plot(t, T_j_dio, 'b');  grid on
ylabel('T_{j}  [^{\circ}C]')
ylim([20 90])
title('T\_dio\_j')
legend('T\_dio\_j','Location','southeast')

% -- 2nd subplot ----------------------------------------------------------
nexttile
plot(t, T_heatSink_dio, 'm');  grid on
ylabel('T_{hs}  [^{\circ}C]')
ylim([20 90])
title('T\_dio\_heat\_sink')
legend('T\_dio\_heat\_sink','Location','southeast')

% -- 3rd subplot ----------------------------------------------------------
nexttile
plot(t, P_losses_dio, 'g');  grid on
ylabel('P_{loss}  [W]')
xlabel('Time  [s]')
ylim([0 6])
title('P\_losses\_dio')
legend('P\_losses\_dio','Location','southeast')
