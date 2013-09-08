BEGIN { groupOk = 0; }
END { print "/** @} */"; }
/\/\/----------------------.*/ {
   if (groupOk == 1) {
        print "/** @ingroup api ";
        print " * @{";
        print " */"; 
    }

    if (groupOk >= 1)  {
        inComm = 1;
        printf ("/**\n");  
    }
    else {
        print $0; 
    }

    groupOk = groupOk + 1;
   next;
   }

/\/\/.*/ { if (inComm) { printf(" * %s\n", substr($0, 3)); }
	else { print $0; } next; }
{ if (inComm) { print " */"; } inComm = 0; print $0; }
	
