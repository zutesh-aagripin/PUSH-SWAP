### COMPILATION ###
C      = gcc
FLAGS  = -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = push_swap
NAME1  = checker

### INCLUDES ###
LIBFT  = libft
HEADER = incl
SRC_PATH  = srcs
OBJ_PATH = objs

### SOURCES ###
PUSHSWAP = push_swap.c
CHEKER = checker.c
COMMON = help.c parse.c stack.c stack2.c stack3.c
ALGO = algo1.c algo2.c algo3.c

### OBJECTS ###

SRCCOMMON = $(addprefix $(SRC_PATH)/,$(COMMON))
SRCALGO = $(addprefix $(SRC_PATH)/,$(ALGO))
SRCPUSH = $(addprefix $(SRC_PATH)/,$(PUSHSWAP))
SRCCHECK = $(addprefix $(SRC_PATH)/,$(CHEKER))
OBJSCOMMON = $(addprefix $(OBJ_PATH)/,$(COMMON:.c=.o))
OBJSALGO = $(addprefix $(OBJ_PATH)/,$(ALGO:.c=.o))
OBJSPUSH = $(addprefix $(OBJ_PATH)/,$(PUSHSWAP:.c=.o))
OBJSCHECK = $(addprefix $(OBJ_PATH)/,$(CHEKER:.c=.o))

### COLORS ###
NOC         = \033[0m
RED         = \033[1;31m
GREEN       = \033[1;32m
BLUE        = \033[1;34m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: tmp $(NAME) $(NAME1)

$(NAME): $(OBJSCOMMON) $(OBJSALGO) $(OBJSPUSH)
	@echo "$(GREEN)Creating lib files$(CYAN)"
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -o $@ $^

$(NAME1): $(OBJSCOMMON) $(OBJSCHECK)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -o $@ $^

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/pws.h
	@$(CC) $(FLAGS) -I $(HEADER) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]$(NOC)"

clean:
	@echo "$(GREEN)Suppressing libraries files$(CYAN)"
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Suppressing libraries files$(CYAN)"
	@make fclean -C $(LIBFT)
	@echo "$(GREEN)Suppressing object files$(CYAN)"
	@rm -rf $(OBJ_PATH)
	@echo "$(GREEN)Removing exucutable files$(CYAN)"
	@rm -f $(NAME)
	@rm -f $(NAME1)

check_error:
	@ echo "$(GREEN) testing for errors $(RED)"
	./checker a 2>&1 | cat -e
	./checker 1 1 2>&1 | cat -e
	./checker 2147483649 2>&1 | cat -e
	./checker 2>&1 | cat -e
	echo "swap" | ./checker "1 2" 2>&1 | cat -e
	echo "sa  " | ./checker "1 2" 2>&1 | cat -e
	echo "  sa" | ./checker "1 2" 2>&1 | cat -e
	./checker -g 2>&1 | cat -e
	./checker -catgv 2>&1 | cat -e
	./push_swap a 2>&1 | cat -e
	./push_swap 1 1 2>&1 | cat -e
	./push_swap -2147483649 2>&1 | cat -e
	./push_swap 2>&1 | cat -e

check_ko: 
	@ echo "$(GREEN) testing for ko $(WHITE)"
	echo "sa\npb\nrrr" | ./checker 0 9 1 8 2 7 3 6 4 5
	echo "sa\npb\nra" | ./checker "3 2 5 1"

check_ok:
	@ echo "$(GREEN) testing for ok $(WHITE)"
	echo "\0" | ./checker 0 1 2
	echo "pb\nra\npb\nra\nsa\nra\npa\npa" | ./checker 0 9 1 8 2
	echo "sa" | ./checker 1 0 2

check_pw:
	@ echo "$(GREEN) testing with pushswap $(WHITE)"
	./push_swap 42
	./push_swap 0 1 2 3
	./push_swap 0 1 2 3 4 5 6 7 8 9
	ARG="2 1 0"; ./push_swap $$ARG | ./checker $$ARG
	ARG="1 5 2 4 3"; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | ./checker $$ARG
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $$ARG | wc -l

check: check_error check_ko check_ok check_pw

analyze:
	@bash test/analyzer.sh

analyze500:
	@bash test/analyzer500.sh

re: fclean
	@$(MAKE) all -j

.PHONY: tmp, re, fclean, clean, all, check, analyze, analyze500
