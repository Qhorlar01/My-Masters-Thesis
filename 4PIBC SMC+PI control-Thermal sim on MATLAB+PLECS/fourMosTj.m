%% 1)  Pull the data out of the structure
% ------------------------------------------------------------------
% Make sure the field name matches what’s in your 'out' structure.
% (Adjust 'MosTemp' if your block is named differently.)
mosfet = out.MosTemp;   

t           = mosfet.time;                  % time vector
T_j         = mosfet.signals(1).values;     % junction temperature
T_heatSink  = mosfet.signals(2).values;     % heatsink temperature
P_losses    = mosfet.signals(3).values;     % power losses

%% 2)  Make the figure larger and increase font sizes
figure(1); clf
set(gcf,'Units','normalized','OuterPosition',[0 0 1 1]);   % full‑screen
set(groot,'defaultAxesFontSize',14);                       % bigger labels
set(groot,'defaultLineLineWidth',1.8);                     % thicker lines

tiledlayout(3,1,"TileSpacing","compact")

% -- 1st subplot ----------------------------------------------------------
nexttile
plot(t, T_j, 'b');  grid on
ylabel('T_{j}  [^{\circ}C]')
title('T\_mosfet\_j')
legend('T\_mos\_j','Location','southeast')

% -- 2nd subplot ----------------------------------------------------------
nexttile
plot(t, T_heatSink, 'm');  grid on
ylabel('T_{hs}  [^{\circ}C]')
ylim([20 50])
title('T\_mosfet\_heat\_sink')
legend('T\_mos\_heat\_sink','Location','southeast')

% -- 3rd subplot ----------------------------------------------------------
nexttile
plot(t, P_losses, 'g');  grid on
ylabel('P_{loss}  [W]')
xlabel('Time  [s]')
title('P\_losses\_mosfet')
legend('P\_losses\_mos','Location','southeast')