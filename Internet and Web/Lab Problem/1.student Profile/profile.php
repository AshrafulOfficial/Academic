<?php
if($_SERVER["REQUEST_METHOD"] === "POST"){
    $fname = $_POST['fname'];
    $lname = $_POST['lname'];
    $gender = $_POST['gender'];
    $roll = $_POST['roll'];
    $nationality = $_POST['nationality'];
    $dob = $_POST['dob'];
    $dept = $_POST['dept'];
    $blood_group = $_POST['blood_group'];

    echo "<h2>Studemt Profile </h2>";
    echo "Name: $fname $lname <br><br>";
    echo "Gender: $gender <br><br>";
    echo "Roll: $roll <br><br>";
    echo "Nationality: $nationality <br><br>";
    echo "Date of Birth: $dob <br><br>";
    echo "Department: $dept <br><br>";
    echo "Blood Group: $blood_group <br><br>";
}
else{
    echo "No data submitted";
}
?>