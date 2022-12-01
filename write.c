/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 03:37:29 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/01 20:16:43 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

 void  placefile(char *file_name)
 {
	int fd;

	fd = open(file_name , O_RDONLY);
	if (fd == -1)//check if this file exist if not will creat the file 
	{
		fd = open(file_name , O_WRONLY| O_APPEND| O_CREAT);
		if (!(fd))
   		{
			perror("Error while opening the file.\n");
      		exit(EXIT_FAILURE);
   		}
	}
	close(fd);
 }

 void overwite(char *file_name, char *str)
 {
	int i;
	int fd;

	i = 0;
	fd = open(file_name, O_CREAT | O_WRONLY, 700);
   if (!(fd))
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
	while(str[i])
		write(fd,&str[i++],1);
	close(fd);
 }
 
 int	ft_strchr(char *str,char c)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c)
			return (-1);
		i++;
	}
	return (i);
}

void append(char *file_name, char *str)
{
	char buff[1];
	int fd;
	int i;
	int z;
	size_t sz;

	i = 0;
	z = 0;
	fd = open(file_name, O_RDONLY| O_WRONLY, 700);
   if (!(fd))
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
	
	while (ft_strchr(buff,'\0') == -1 && read(fd,buff,1) > 0)
	{
		while(str[i++])
			write(fd,&str[i],1);
		printf("excuted");
	}
	close(fd);
}

 int main()
 {
	// placefile("test.txt");
	// overwite("test.txt","this is for testing");
	// append("test.txt","this is for test\n");
	
	return 0;
 }