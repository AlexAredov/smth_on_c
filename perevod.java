package com.company;


import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner vvod = new Scanner(System.in);

        System.out.println("Input a number: ");
        int num = vvod.nextInt();

        System.out.println("Input a base: ");
        int num1 = vvod.nextInt();

        String s = "";
        if (num1 < 11){
            while (num > 0){
                s = String.valueOf(num % num1) + s;
                num = num / num1;
            }
        }
        else{
            while (num > 0){
                if (num % num1 == 10){
                    s = "A" + s;
                }
                else if (num % num1 == 11){
                    s = "B" + s;
                }
                else if (num % num1 == 12){
                    s = "C" + s;
                }
                else if (num % num1 == 13){
                    s = "D" + s;
                }
                else if (num % num1 == 14){
                    s = "E" + s;
                }
                else if (num % num1 == 15){
                    s = "F" + s;
                }
                else{
                    s = String.valueOf(num % num1) + s;
                }
                num = num / num1;
            }
        }

        System.out.printf("Your number: %s \n", s);
    }
}
