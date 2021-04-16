function output = sum_product(n)
    output = 0;
    for i = 1 : n
        k = 1;
        for q = 1 : i
            k = k * q;
        end
        output = output + k;
    end
    
