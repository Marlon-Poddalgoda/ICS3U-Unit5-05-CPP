// Copyright (c) 2020 Marlon Poddalgoda, All rights reserved
//
// Created by Marlon Poddalgoda
// Created on January 2021
// This program formats a user inputted address into a mailing address

#include <iostream>
#include <algorithm>
#include <string>


std::string Mailing(std::string name, std::string srtNum,
                    std::string srtName, std::string city,
                    std::string province, std::string postCode,
                    std::string aptNum = "") {
    // This function converts an address to a mailing address

    std::string mailAddress;

    // process
    mailAddress = name;
    if (aptNum != "") {
        mailAddress = (mailAddress + "\n" + aptNum + "-" + srtNum +
                        " " + srtName + "\n" + city + " " + province + "  "
                        + postCode);
    } else {
        mailAddress = (mailAddress + "\n" + srtNum +
                        " " + srtName + "\n" + city + " " + province + "  "
                        + postCode);
    }
    // capitalization
    std::transform(mailAddress.begin(), mailAddress.end(), mailAddress.begin(),
                   ::toupper);

    return mailAddress;
}


main() {
    // this function gets user input
    std::cout << "This program formats your address to a mailing address"
              << std::endl;
    std::cout << "" << std::endl;

    // variables
    std::string name;
    std::string question;
    std::string aptNum = "";
    std::string srtNum;
    std::string srtName;
    std::string city;
    std::string province;
    std::string postCode;
    std::string address;

    // input
    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Do you live in an apartment? (y/n): ";
    std::getline(std::cin, question);
    if (question == "y" || question == "yes") {
        std::cout << "Enter your apartment number: ";
        std::getline(std::cin, aptNum);
    }
    std::cout << "Enter your street number: ";
    std::getline(std::cin, srtNum);
    std::cout << "Enter your street name: ";
    std::getline(std::cin, srtName);
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Enter your province (As an abbreviation, ex: ON, BC..): ";
    std::getline(std::cin, province);
    std::cout << "Enter your postal code (123 456): ";
    std::getline(std::cin, postCode);
    std::cout << "" << std::endl;

    // call functions
    if (aptNum != "") {
        address = Mailing(name, srtNum, srtName, city, province, postCode,
                          aptNum);
    } else {
        address = Mailing(name, srtNum, srtName, city, province, postCode);
    }
    // output
    std::cout << address << std::endl;
}
