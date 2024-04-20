# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davgalle <davgalle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 11:35:32 by davgalle          #+#    #+#              #
#    Updated: 2024/04/20 17:36:57 by davgalle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=thread

RM = rm -f

LIB = ar rcs

SRC = src/main.c \
	  src/error.c \
	  src/checker.c \
	  src/data_init.c \
	  src/auxiliar.c \
	  src/init.c \
	  src/threads.c \
	  src/threads_sync.c \
	  src/routine.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	
all: 

	@clear
	@echo ";ccloooddxxxxxddl,......       .'..'..'.......  ........  ...',,'...,;;:coxxxdxkOkkxxxdooolllc;,,,,'"
	@echo ";clloddxxxxkkkd:..';'.  .  ....'. ....... ... 'c:'...  ..,;;,'.....'c:,,,;ldxxxkOOOOOkkxxddolc:;;;;,"
	@echo ":lloodxxxxkxxo,......  ........... .....   .. .kXx:.  .,;'....  .....';c;,coddxkOOOOOOOkkkxxoc:::::;"
	@echo "loooddxxxxxkx:..'.................    .       .kNd'. .:,.........''.''';llcldxkkOOOO000OOOOOxolccllc"
	@echo "loooddxxkkkkl..,,'.......                     .';,...:c;,'.....  .',;,',;;cokOOOOOOOO0OO00000Okxddol"
	@echo "loooddddxxxl. ..........                           .,llcc,'''.. ..',,,'':okOkkkOOOOO000000000OOOkxol"
	@echo "ooooooddool'..'.......                      ..     .;::,,'.... ..;;okkxk0K0OOkkOOO0000000000OOOOkxdo"
	@echo "oddxxxxxxd:..........           ..    ..........   .,;'........,cccxKXKKKK000OOOOO000000000000OOkkxx"
	@echo "oddddxxxko..........     .   ....  .......''.........''.';:cllcldkdloOXXKKKKK00000KKKKKKKKKKK00OOkkx"
	@echo "ddddddddxc..........  ..................,;,..''''...;;,.',:cc::ccc;,':OKXXXXXKKKKKKKKKKKKKKK0000OOOk"
	@echo "xxxxddddxc..,'.....  .,. .............':;,'',;::;...,,''',;;'.,:,.....':lx0XXXXKKXXKKKKKKKKK00000OOk"
	@echo "dxxdddxdxo'.......   ............''',;c:.''',,,','..,:;;:::;,',,,,,.......,oxk0XXXXXXXKKKKKK00OO00OO"
	@echo "dddddddxxl'.....    .c'.........,;,,:cc:,;,''',;;'...',,,'..''',,;::,......'':ok0KXXXXXKKK0000OOOOOO"
	@echo "oddddddool,.''....  co.........',;',cc::;:c::ccc;'.....','''..';clol;''';coookkdx0XXXXXKK00000000000"
	@echo "ooddddxxdxc'','.    cc........',''',;;,;;,::ccc:,.....';,,;::lodxkkOkxxxxxdodx0OkO0XNXXKKKKK00000000"
	@echo "dxxxdddxkOx;...     ;;........'',,;'',',;::::;,'...',c:',cllllclododddxxxdll:oxldxOXXXXKKKKKKKKK0000"
	@echo "xxkkkxxxkkOo'''..   ''........';c::,',,:l;'''',;cooddo;,lddc:ocoxxkkxxxddl;::dkld0KNXXXKKKXXXXKKKK00"
	@echo "xxxxxkkkkkkkc',;'     ....'..'';ccc;,;,;:'..,cloxxkxdoc:ooxoldlodd0KKKKOkdxdclxOKXXXNNNXKXXXXXXXKKK0"
	@echo "xxddxxxxxkkkx;.,'.     ...''.'',;;;;;;,;:;'.,llldkOOko::ccdOkdx00KXXNNNNKOxox00KXXXXXNXXXXXXXXXXXKKK"
	@echo "xxdddddddxxxko,''.      ...'''''.',,,,lo;,'..,;,,:llxo,,codxxk000KKKK0KNNKkk000KXXKKXXXXXXXXXXXXXXXX"
	@echo "xdddddddddddxko,...     ....'''..''''lkl;:;.... .';;oo',lxxOO0KKKK00Okkkxkk0NXKKXXXXKXXXXKKKKXXXKKKX"
	@echo "ddddddddddddxxxd,...     .........'';dxolc:;:' .,'';:;:lcldOKKXN0kkxlcodcoOKNNXNNNNNXXXXXXXXXXXXKKKK"
	@echo "ddddddddodddxxxkd,...     .......',,cko:lcccc;..:c;,..:odxk0XNWWWNN0kk00O0KXNNNNNNNNNXXXXXNNNNNNXXKK"
	@echo "dddddddoodddddxxxd;''..     ....,,,;lko:ldl;;::,',;;'':oxO0KNNWWMWWXXNNNXNNNNNNNWWWNNNNNNNNNNNNNNNNX"
	@echo "oddddoooddddddxxxxxc'...     ..,;;;::;:cldd:,cddolll:;lOO0KXNNWWWWWNNWWWNWNNNXNNWWNNNWWWWWNNNNNNNNNN"
	@echo "oddddoooddoodddxxxkkl''..   ..',,,;:c:,:loddlc:cllol::dkO0KNNNWWWWWNNWWWNNWNNNNNNNNNNWWWWNWWNNNNNNNN"
	@echo "dxxddoloodoooddxxxkOk:',.. ..',,'.';cooccloxkxolloooolokOKXNNNWWWWNNK0XXXNWNNWWWNNNNNWWWWNNWWNNNNNNN"
	@echo "xddooollodooooddxxxxkl,,'...'......',;c::oxkkxdooddxxxxO0KXXNNNNNNNN0kxodOKNWWWWWNNWWNNWWWNNWNNNNNNN"
	@echo "doolllloooollooddxxxxl,,'.....''....';;:coxOOxooodxxxkkO0KXXNNWWWX0XNXOxkOKNWWWWNWWWWWNNWWWWWNNNNNNN"
	@echo "doollllooollllodddxxx:'''........';:ccllldk00OxoodxxxkO0KKKXXNWWWX00K0KNWWWWWWWWWWWWWWWWWWWWWNNNNNNN"
	@echo "ooollllllllccllooddxo,.,,..,,...,::cllolldxO00OxddddxxkkOO0KNWWWWWWK00NWWWWWWWWWWWWWWWWWWNNWWWNNNNNN"
	@echo "oolloollllllcllloodl,.,cc'.....,;clloodoodxO0K0OxxxddddxxkO0KXNNWWWK0XWWWWWWWWWWWWWWWWWWWNNWWNWWNNNN"
	@echo "lllloooooodollllol:',:cll:'. .',:cllooooddxOKK00OOOOkxxddxxxkkO0KKXXWWWWWWWWWWWWWWWWWWWWWNNNWWWWNNNN"
	@echo "lllllllollooddlc;'',:c:cc;....,;:cclooodddxk0KKKKKK000kdccodddxxxk0XWWWWWWWWWWWWWWWWWWWWWNNNWWWWWNNN"
	@echo "clclllloolc:;,'...''',''.....',:cllloooododk0KXNNXXXNXKOodXNNNNNNNWWWWWWWWWWWWWWWWWWWWWWNNNNNWNNWNNN"
	@echo "cccc;,',;'.   ..............',:cclloooooooxOKXNNNNNNWWWN0xdoxO0XWWWWWWWWWWWWWWWWWWWWWWNNNNNNNNNNNNNN"
	@echo "c:,'.......  ...........'''',;:cclodddoolox0XNWNNNNNNWNNk' ..,cdk0KNWWWWWWWWWWWWNWWWWWWNNNNNNNNNNNNX"
	@echo ";...........'''','',,,;;,,;;:cclloddddolodx0XNWWNNXNNWNXd....':oxdodONWWWWWWWWNNNNNNNNNNNNNNNNNNNNNN"
	@echo ".........'',,,',,,,',;;;;:;;clooodxxdddddxk0KNWWNNNNWNKXx'..';lx0Kxld0XWWWNNWWWWNNNNNNNNNNNNNNNNNNNX"
	@echo "...''''.',;,;;;,,,;;,,,;cc:::codddxdddO0OkkOKNNNNNNNNXXNO;.'',:clxc.;okXWWNNWWWWNNNNWNNNNNNNNNNNNNNX"
	@echo "','';;;;'';:::;;;;:::'';:;;::::loodoodOXXKOO0NWNNNNWWWWNOc;,;;::;:c;,:xXNNNNNWWWWNNNNNNNNNNNNNNNNNNX"
	@echo ",::;,ll:,';cc:;:;,;:;:,',;::::;:clllllxO0000KNWNNWWWWWWXkol:;::cc:;,,,lk0XNNNWNNNNNNNNNNNNNNNNNNNNNX"
	@echo "lool:coc:',cl:cc:,,:;;:,';:cc:c:;:ccclloddxkOKNXXXXXXNNKOdol;;cllc::,',,;cd0NWNNNNNNNNNNNNNNNNNNNNNX"
	@echo "lxkxclxdl,'coc:::;;cc;::,':cccllccc:;ccldddxkOO0OkkkOOkxxxdoc;;:::ccc,,;;;;:d0NNNNNNNNNNNNNNNNNNNNXK"
	@echo "odxxloOkd:'lxlc:c:;cl:;::',ccloooc:::lddllooddddddddddddoooolc;,:clccc,,;::;;:xKNNNNNNNNNNXNNNNNNNXK"
	@echo "k00Odd0Odc,lkocccc;:oc;:c;.,lllllllcccllc:colcclccc:codddddooo:;;:cccc:,;::c:;:lOXNNNNNNNNXXNNNNNNXK"
	@echo "k0K0dd00xl;okl:ccc;;ol;:c:,':lc:clolccccloxkxdoccl:cc:::llloooccc;;:::c;;:ccc::clxKNXXXXXXXXNNXXNXX0"
	@echo "x0K0xdO0kl;okocc::,;do;:cc;'.;cclooccccoxkkkxkkkOxlc,;cc,;lolcooll;,;:c;,cccc::cccokXNXXXXKXXNXXXXX0"
	@echo "k0KK0OOkd:,lkdc::;;cxd::cc:,',odoooooodddxxxxxxxxxdc;cdd:;oocoxddoolccl;,:lllc:cccclxKNXXXKKXXXXXXK0"
	@echo "x0000Okkxc,lxl:;;;:cdd::ccc:,;oko::lloxkkkkxooxxddxl:cdkdoddddolooodocc;,:lll::clccllkXKKK00K000000k"
	@echo "	"
	@echo "   ██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗"
	@echo "   ██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝"
	@echo "   ██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗"
	@echo "   ██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║"
	@echo "   ██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║"
	@echo "   ╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝"
                                                                                                                                                                                                                                      

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re