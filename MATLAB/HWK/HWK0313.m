function [output1, output2] = in(n1, n2)
    output1 = 0;
    output2 = 0;
    for i = 1 : n1
        k = 1;
        for q = 1 : i
            k = k * q;
        end
        output1 = output1 + k;
    end
    
    for op = 1 : n2
        if rem(op,2) == 0
            output2 = output2 - op;
        else
            output2 = output2 + op;
        end
    end
    output1
    output2
