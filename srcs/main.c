#include "../include/libasm.h"

int main(void) {
	char 	*str = "Bonjour les amis!";
	char	*str1 = "Bonjour les amis!";
	char	*str2 = "ANot the same";
	char	*str3 = "Not the same but much bigger!!!";
	char	dst1[100];
	char	dst[100];
	bzero(dst, 100);
	bzero(dst1, 100);
	/*char	*dst = malloc(sizeof(char) * strlen(str));
	if (dst == NULL)
		return (1);*/
	size_t	size = 0;
	size_t	size1= 0;

	/*	FT_STRLEN	*/
	size = ft_strlen(str);
	printf("my function strlen: %ld\n", size);
	size1 = strlen(str);
	printf("stdlib function strlen: %ld\n", size1);
	printf("2nd ft_strlen test: %ld\n", ft_strlen("I can even have the lenght of a literal string!"));
	printf("stdlib function: %ld\n", strlen("I can even have the lenght of a literal string!"));

	/*	FT_STRCPY	*/
	ft_strcpy(dst, str);
	printf("my function strcpy: %s\n", dst);
	strcpy(dst1, str1);
	printf("stdlib function strcpy: %s\n", dst1);
	//free(dst);

	/*	FT_STRCMP	*/
	printf("it is equal so: %d\n",ft_strcmp(str, str1));
	printf("right answer: %d\n", strcmp(str, str1));
	printf("it is smaller so: %d\n", ft_strcmp(str1, str3));
	printf("right answer: %d\n", strcmp(str1, str3));
	printf("it is bigger so: %d\n", ft_strcmp(str3, str2));
	printf("right answer: %d\n", strcmp(str3, str2));

	/*	FT_WRITE	*/
	ft_write(-1, "ft_write: Bonjour tout le monde!\n", ft_strlen("ft_write: Bonjour tout le monde!\n"));
	if (errno != 0)
		printf("ft_write error: %s\n", strerror(errno));
	ft_write(1, "ft_write: Cette fois ca marche!\n", ft_strlen("ft_write: Cette fois ca marche!\n"));
	write(-1, "stdlib: Bonjour tout le monde!\n", strlen("stdlib: Bonjour tout le monde!\n"));
	if (errno != 0)
		printf("stdlib: %s\n", strerror(errno));
	write(1, "stdlib: Cette fois ca marche!\n", strlen("stdlib: Cette fois ca marche!\n"));

	/*	FT_READ	*/
	char	buffer[1000];
	bzero(buffer, 1000);
	int		fd = open("./Makefile", O_RDONLY);
	int		fd2 = open("./Makefile", O_RDONLY);
	int		r_count = 0;
	int		r_count2 = 0;

	r_count = ft_read(fd, buffer, 1000);
	printf("ft_read: %s\n", buffer);
	printf("read count is: %d\n", r_count);
	r_count2 = read(fd2, buffer, 1000);
	printf("stdlib: %s\n", buffer);
	printf("stdlib read count is: %d\n", r_count2);
	close(fd);
	close(fd2);
	ft_read(-1, buffer, 1000);
	if (errno != 0)
		printf("ft_read error: %s\n", strerror(errno));
	read(-1, buffer, 1000);
	if (errno != 0)
		printf("stdlib: %s\n", strerror(errno));

	/*	FT_STRDUP	*/
	char	*temp = NULL;
	char 	*temp2 = NULL;

	temp = ft_strdup("hello there\n");
	if (temp)
		printf("ft_strdup: %s\n", temp);
	temp2 = strdup("hello there\n");
	if (temp2)
		printf("stdlib: %s\n", temp2);
	free(temp);
	free(temp2);
	return (0);
}
