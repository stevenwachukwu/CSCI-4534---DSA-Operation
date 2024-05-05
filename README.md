Programming Problem (35 points): What you have to turn in and where you have to turn it in is similar to how you
needed to turn in stuff for the earlier HW including the self-critique, the easy to read source code, a printout of the output
in the main HW3 submission (along with all the other HW3 stuff, all of this to be turned in as a single pdf file) and the
actual program in the Programming Problem submission.
You have to write a program to implement DSA. Your program will take as input p, q, h, x, k, a “real” value H(M1), and a
“fake” value H(M2) (which will be different from H(M1)). Your program should
1. first calculate g and y and then print these values.
2. then calculate (for H(M1)) the signature (r, s) and then print these values.
3. then make sure that DSA works correctly on real values by verifying that (r, s) is the signature for H(M1) by calculating
w, u1, u2, v and testing whether v = r? Your program should print w, u1, u2, v and the result of the test.
4. then make sure that DSA works correctly on fake values by verifying that (r, s) (use the same r, s values as you
calculated for H(M1)) is not the signature for H(M2) by calculating w, u1, u2, v and testing whether v = r? Your
program should print w, u1, u2, v and the result of the test. Here what you are making sure of is that if BG tries to
forge a signature of a new message by using an old signature, this should not work.
You have to run your program on three different inputs.
1. the example discussed in class and in the handout: p = 7, q = 3, h = 3, x = 2, k = 1, H(M1) = 3, H(M2) = 4.
2. p = 47, q = 23, h = 5, x = 7, k = 13, H(M1) = 5, H(M2) = 4.
3. An input generated by you - you should generate the largest values for which you can get correct results in a “reasonable”
amount of time.
