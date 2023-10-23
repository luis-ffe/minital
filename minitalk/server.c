/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:22:42 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/21 23:41:42 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    function(int sig)
{
    static int i;
    static unsigned char c;

    /*fazer a manipulação de bits
    porque isto é camado na estrutura do main e faz a impressao total por bits
    */
}

/* appontamentos caderno ver e  operaçoes de bits
conseguir o pid e enviar o pid 
kill para enviar 
*/
int main(void)
{
    struct sigaction s_sigaction;
    s_sigaction.sa_sigaction = function; ????
    s_sigaction.sa_flags = SA_SIGINFO;
    
    /*
    imprimir isto:
    Server PID: nbr \n    
    */

   sigaction(SIGURS1, &s_sigaction, NULL);
   sigaction(SIGURS2, &s_sigaction, NULL);
    while(1)
    {
        pause();
    }
    return (0);
}