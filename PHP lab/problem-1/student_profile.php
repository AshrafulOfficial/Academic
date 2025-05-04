<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $name = htmlspecialchars($_POST["name"]);
  $email = htmlspecialchars($_POST["email"]);
  $phone = htmlspecialchars($_POST["phone"]);
  $dob = htmlspecialchars($_POST["dob"]);
  $gender = htmlspecialchars($_POST["gender"]);
  $address = htmlspecialchars($_POST["address"]);
  $department = htmlspecialchars($_POST["department"]);
  $gpa = htmlspecialchars($_POST["gpa"]);
} else {
  echo "No data submitted.";
  exit;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8" />
  <title>Student Profile</title>
  <style>
    body { font-family: Arial; padding: 20px; }
    table { border-collapse: collapse; width: 60%; }
    td, th { border: 1px solid #ddd; padding: 8px; }
    th { background-color: #f2f2f2; }
  </style>
</head>
<body>
  <h2>Student Profile Details</h2>
  <table>
    <tr><th>Attribute</th><th>Value</th></tr>
    <tr><td>Full Name</td><td><?= $name ?></td></tr>
    <tr><td>Email</td><td><?= $email ?></td></tr>
    <tr><td>Phone</td><td><?= $phone ?></td></tr>
    <tr><td>Date of Birth</td><td><?= $dob ?></td></tr>
    <tr><td>Gender</td><td><?= $gender ?></td></tr>
    <tr><td>Address</td><td><?= $address ?></td></tr>
    <tr><td>Department</td><td><?= $department ?></td></tr>
    <tr><td>GPA</td><td><?= $gpa ?></td></tr>
  </table>
</body>
</html>
