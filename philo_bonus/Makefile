NAME = philo_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

INDIR = src/
OUTDIR = obj/
HFLAGS = -I $(INDIR)
HFILES = philo_bonus.h

SRCS =  $(INDIR)philo_bonus.c 	\
		$(INDIR)check.c 	\
		$(INDIR)io.c 		\
		$(INDIR)init.c		\
		$(INDIR)routine.c	\
		$(INDIR)semaphore.c	\
		$(INDIR)monitor.c	\
		$(INDIR)events.c	\
		$(INDIR)destroy.c	\
		$(INDIR)time.c		\
		$(INDIR)parse.c

OBJS = $(SRCS:$(INDIR)%.c=$(OUTDIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(HFLAGS) $(OBJS) -o $(NAME)

$(OUTDIR)%.o: $(INDIR)%.c $(HFILES)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(HFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OUTDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
