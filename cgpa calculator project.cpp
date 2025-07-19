#include <iostream>
#include <string>
#include <vector>

int main() 
{
    int num_classes;
    std::cout << "Enter the number of classes you are taking this semester: ";
    std::cin >> num_classes;
    std::cin.ignore(); // Consume newline character after integer input

    std::vector<std::string> all_classes(num_classes);
    std::vector<std::string> grade(num_classes);
    std::vector<double> credits(num_classes);
    std::vector<double> qualitypts(num_classes);

    std::cout << "\nEnter your class names. Hit enter after typing each class name.\n";
    for (int i = 0; i < num_classes; ++i) 
    {
        std::cout << "Class " << i + 1 << ": ";
        std::getline(std::cin, all_classes[i]);
    }

    double total_credits = 0, total_quality_points = 0;

    for (int i = 0; i < num_classes; ++i) 
    {
        std::cout << "\nEnter your grade for " << all_classes[i] << ": ";
        std::getline(std::cin, grade[i]);

        std::cout << "Enter credit hours for " << all_classes[i] << ": ";
        std::cin >> credits[i];
        std::cin.ignore(); // Consume the newline

        total_credits += credits[i];

        // Assign quality points based on the grade
        double grade_value = 0.0;
        if (grade[i] == "A" || grade[i] == "A+" || grade[i] == "a" || grade[i] == "a+") grade_value = 4.0;
        else if (grade[i] == "A-" || grade[i]=="a-") grade_value = 3.67;
        else if (grade[i] == "B+" || grade[i] == "b+") grade_value = 3.33;
        else if (grade[i] == "B" || grade[i] == "b") grade_value = 3.00;
        else if (grade[i] == "B-" || grade[i] == "b-") grade_value = 2.67;
        else if (grade[i] == "C+" || grade[i] == "c+") grade_value = 2.33;
        else if (grade[i] == "C" || grade[i] == "c") grade_value = 2.0;
        else if (grade[i] == "C-" || grade[i] == "c-") grade_value = 1.67;
        else if (grade[i] == "D+" || grade[i] == "d+") grade_value = 1.33;
        else if (grade[i] == "D" || grade[i] == "d") grade_value = 1.0;
        else if (grade[i] == "D-" || grade[i] == "d-") grade_value = 0.67;
        else grade_value = 0.0; // For F or invalid input

        qualitypts[i] = credits[i] * grade_value;
        total_quality_points += qualitypts[i];
    }

    // Calculate GPA
    double gpa = (total_credits > 0) ? (total_quality_points / total_credits) : 0.0;

    std::cout << "\nYour GPA for this semester is: " << gpa << "\n";

    return 0;
}


