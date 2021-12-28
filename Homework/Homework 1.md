

Problem 1
A,B,C = 0

Procedure A      Procedure C            Procedure B
V(A)                   V(C)                              V(B)
print A                print c                           print b
P(C)                   if(A = 0)                        P(C)
                               P(B)
                               goes B
                          Else if (B = 0)
                               P(A)
                               goes to A
                          End if
		  Go to top

Though:
	In order to find the correctness of finding the 3 order of the procedure. We know that A or B can go first. Procedure C has to go in between them. If A or B goes first than C follows afterward. Then it should alternate between A and C. So procedure A and B should be a mirror with each other. We start by setting A,B,C to zero. We mirror A and B to look exactly like each other bumping the number in the procedure by one and printing out the letter. After that they need to go to procedure C, so P is use to set it to -1. Now Both procedure if it start from A or B will have to go to C. C will be incremented  and print there letter C. Now we will check in an if statement to see if A or B is equal to 0, if one of them are, it will go into the loop and goes to that procedure to print the next letter. It will just keep looping to print out ACBCACBCA or BCACBACBCA.

Starvation
	There are no starvation in the program. They do get blocked at some point, but they will continue to make progress with there procedure once the procedure become unblock.

DeadLock
 	There are no deadlock in the code. It won’t be able to print the order if deadlock occurs.







Problem 2

procedure Robot A
	loop
		compute briefly
		P(A0A1) //lock out A0 A1
		P(B0A0)
		occupy A0
		return to base
		V(A0A1) //resume A0 A1
		V(B0A0)
		compute a little while
		P(B0A0)
		occupy B0
		V(B0A0)
		return to base
	end loop
end procedure

procedure Robot B
	loop
		calculate for a moment
		P(B0A0)
		occupy B0
		return to base
		V(B0A0)
		calculate a little more
		P(B2B1)
		occupy B1
		return to base
		V(B2B1)
	end loop
end procedure

procedure Robot C
    loop
        await a shipment
        P(A0A1)
        occupy A1
        return to base
        V(A0A1)
        await a 2nd shipment
        P(B2B1)
        occupy B1
        return to base
        v(B2B1)
    end loop
end procedure

procedure Robot D
    loop
        P(A0A1)
        P(B0A0)
        occupy A0
        return to base
        V(B0A0)
        V(A0A1)
        intermission control
        P(B2B1)
        P(B2A2)
        occupy B2
        return to base
        V(B2A2)
        V(B2B1)
        download new instruction
    end loop
end procedure
        
procedure Robot F
    loop
        check inventory
        P(A0A1)
        occupy A1
        return to base
        V(A0A1)
        do a quick calculation
        P(B2A2)
        occupy A2
        return to base
        V(B2A2)
    end loop
end procedure
  



Thoughts        
If a robot want to occupy the square A0, it can only occupy A0 if (A0,A1) and (B0,A0)
are empty. If A0 is occupy than  A0,A1 and B0 will be locked.

If a robot want to occupy the square A1, it can only occupy A0 if (A0,A1) is empty. If
A0 is occupy than A0 and A1 will be locked.

If a robot want to occupy the square A2, it can only occupy A2 if (B2,A2) is empty. If
A2 is occupy than B2 and A2 will be locked.

If a robot want to occupy the square B0, it can only occupy B0 if (B0,A0) is empty. If
B0 is occupy than B0 and A0 will be locked.

If a robot want to occupy the square B1, it can only occupy B1 if (B2,B1) is empty. If
B1 is occupy than B2 and B1 will be locked.

If a robot want to occupy the square B2, it can only occupy B2 if (B2,A2) and (B2,B1) are empty.
if B2 is occupy than B1,B2 and A2 will be locked.



Starvation
There are no starvation on the program, because each process gets a turn and does not get stuck.

Deadlock
If a robot attempt to occupy A0 and B2. Both cases will interpret between P operation either because the second resource is taken.

