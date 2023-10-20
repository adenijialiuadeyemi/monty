 ++++[>++++[>+++<-]<-]   output 48 / 0x30 / '0' in cell(2)
    ,>,>                    scan two numbers in cell(0) and cell(1)
    [<-<->>-]               decr cell(0) and cell(1) by 48 / 0x30 / '0'
    <<                      move to cell(0)
    [                       loup multiply
        >                   go to cell(1)
        [>+>+<<-]           take cell(1) to cell(2) and cell(3)
        >>                  go cell(3)
        [<<+>>-]            take cell(3) back to cell(1)
        <<<-                decr cell(0)
    ]
    >[-]<                   set cell(1) to 0 so that it can be used as counter (we are in cell 0 here)
    ++++[>++++[>+++<-]<-]   adding 48 / 0x30 / '0' to cell(2) cell 2 has the result
    >>.                     print result (go to cell 2 and print)
