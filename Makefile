#varible
CC=gcc
object=book.o diff.o dynamic_pricing.o Passengerdetails.ompleto payment_complete.o print_date1_time.o web_check_in.o cancellation.o mainfile.o
target=compare_interests
#target name
final_project: book.o diff.o dynamic_pricing.o Passengerdetails.o payment_complete.o print_date1_time.o web_check_in.o cancellation.o mainfile.o
	gcc book.o diff.o dynamic_pricing.o Passengerdetails.o payment_complete.o print_date1_time.o web_check_in.o cancellation.o mainfile.o -o final_project

payment_complete.o: payment_complete.c
	gcc -c payment_complete.c

print_date1_time.o: print_date1_time.c
	gcc -c print_date1_time.c

web_check_in.o: web_check_in.c
	gcc -c web_check_in.c

cancellation.o: cancellation.c
	gcc -c cancellation.c

web_check_in.o: web_check_in.c
	gcc -c web_check_in.c

book.o: book.c
	gcc -c book.c

Passengerdetails.o: Passengerdetails.c
	gcc -c Passengerdetails.c

diff.o: diff.c
	gcc -c diff.c

mainfile.o: mainfile.c
	gcc -c mainfile.c

clean: 
	rm -f $(object) $(target)
