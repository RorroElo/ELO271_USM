u_1 = out.u_1;
u_2 = out.u_2;
w = out.w;
y = out.y;
unos = ones(length(u_1),1);
Phi = [unos u_1 u_2];
a = Phi\y;