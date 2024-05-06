information('sakshi','danej','sakshi@gmail.com','43999494850').
information('priti','pandey','priti@gmail.com','580333850').
information('nupoor','aher','nupoor@gmail.com','20394850').
information('parul','habib','parul@gmail.com','39485033333').

get_information(LastName, Info) :- information(_, LastName, Info,_).





get_information('danej', Info).