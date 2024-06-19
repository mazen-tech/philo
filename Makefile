# BASIC
CC = cc -g -pthread
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
GDB = gdb
    
# TESTING
VAL = valgrind --leak-check=full --track-origin=yes
SANITIZE_THREAD = -fsanitize=thread
SANITIZE_ADDRESS = -fsanitize=address
HELGRIND = valgrind --tool=helgrind
DRD = valgrind --tool=drd

# COLORS
RESET			:= \033[0m
GREEN			=	\e[32m
CYAN			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m
RED				:= \033[1;31m
BOLD			:= \033[1;1m

# PHILOSOPHERS
NAME =	philo.a
SRCS =  src/args.c \
        src/check.c \
		src/init.c \
		src/philo.c \
		src/simulation.c \
		src/threads.c \
		src/time.c \
		src/utils.c \

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE RULES
all: $(NAME) philo

$(NAME): $(OBJS)
	@echo "$(GREEN)$(BOLD)Creating objects ...$(RESET)"
	ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Objects has created!$(RESET)"
	
$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

philo: $(PHILO_OBJ) $(NAME)
	@echo "$(GREEN)$(BOLD)Creating executable...$(RESET)"
	$(CC) $(CFLAGS) $(PHILO_OBJ) $(NAME) -o philo
	@echo "$(GREEN)$(BOLD)Executable has created!$(RESET)"

clean:
	@echo "$(RED)$(BOLD)Removing objects...$(RESET)"
	$(RM) $(OBJSDIR)
	@echo "$(RED)$(BOLD)Objects has removed!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executable...$(RESET)"
	$(RM) philo philo.a
	@echo "$(RED)$(BOLD)Executable has removed!$(RESET)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Recompiled successfully!$(RESET)"

.SILENT: