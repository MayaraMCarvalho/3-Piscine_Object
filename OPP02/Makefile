# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 16:33:22 by macarval          #+#    #+#              #
#    Updated: 2025/10/01 14:02:40 by macarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

git:
			clear
			git add .
			git status
			@echo "$(GREEN)Enter cpp list:"
			@read list; \
			echo -n "\n"; \
			echo "$(YELLOW)Enter the exercise:"; \
			read ex; \
			echo -n "\n"; \
			echo "$(MAGENTA)Choose status:"; \
			echo "1. Init."; \
			echo "2. In Progress..."; \
			echo "3. Done!!"; \
			echo "4. Correction"; \
			echo "5. Bonus"; \
			read status_choice; \
			case $$status_choice in \
						1) status="Init." ;; \
						2) status="In Progress..." ;; \
						3) status="Done!!" ;; \
						4) status="Correction" ;; \
						5) status="Bonus" ;; \
						*) echo "Escolha inválida"; exit 1 ;; \
			esac; \
			echo -n "\n"; \
			echo "$(GREEN)Enter the commit message:"; \
			read msg; \
			echo -n "\n"; \
			echo "$(BLUE)"; \
			git commit -m "[Cpp$$list]: ex$$ex - ($$status) $$msg"; \
			git push

.PHONY:		git
