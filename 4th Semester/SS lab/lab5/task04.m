% Define the complex numbers
z1 = 3 + 2i;
z2 = -1 - 4i;

% Compute z^2 and conj(z)
z_sq1 = z1^2;
z_conj1 = conj(z1);

z_sq2 = z2^2;
z_conj2 = conj(z2);

% Compute z^2 / conj(z)
result1 = z_sq1 / z_conj1;
result2 = z_sq2 / z_conj2;

% Display the results numerically using zprint
fprintf('z1^2: ');
zprint(z_sq1);
fprintf('\n');

fprintf('Conjugate of z1: ');
zprint(z_conj1);
fprintf('\n');

fprintf('z1^2 / conj(z1): ');
zprint(result1);
fprintf('\n');

fprintf('z2^2: ');
zprint(z_sq2);
fprintf('\n');

fprintf('Conjugate of z2: ');
zprint(z_conj2);
fprintf('\n');

fprintf('z2^2 / conj(z2): ');
zprint(result2);
fprintf('\n');
