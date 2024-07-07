n = input("Enter the number of node points: ");
X = zeros(1,n);
f = zeros(1,n);
for i = 1:n
    fprintf("Enter the value of x_%d: ", i - 1)
    X(i) = input("");
    fprintf("Enter the value of f(x_%d): ", i - 1)
    f(i) = input("");
    if i==1 
        maxa = X(1);
        mina = X(1);
    elseif X(i) < mina
        mina = X(i);
    elseif X(i) > maxa
        maxa = X(i);
    end
end

x = linspace(mina, maxa, 10000);
y = zeros(1,10000);
for i = 1:n
    y = y + ((l(i, x, n, X) * f(i)) / li(i, n, X));
end
% disp(y)
plot(x,y)

function result = l(i, x, n, X)
    result = ones(1,10000);
    for j = 1:(i-1)
        result = result .* (x - X(j));
    end
    for j = (i+1):n
        result = result .* (x - X(j));
    end
end

function result = li(i, n, X)
    result = 1;
    for j = 1:(i-1)
        result = result * (X(i) - X(j));
    end
    for j = (i+1):n
        result = result * (X(i) - X(j));
    end
end