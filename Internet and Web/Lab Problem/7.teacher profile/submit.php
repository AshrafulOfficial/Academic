<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "teacherdb";

$conn = mysqli_connect($servername, $username, $password, $dbname);
if(!$conn){
    die("Connection Failed".mysqli_connect_error());
}

if($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["name"])){
    $name = $_POST["name"];
    $subject = $_POST["sub"];
    $email = $_POST["email"];
    $phone = $_POST["phone"];
    
    $sql = "INSERT INTO teacher_profile(name,subject,email,phone)
    values('$name', '$subject', '$email', '$phone')";

    if(mysqli_query($conn, $sql)){
        echo "New Record Created Successfully";
    }else{
        echo "Error: ".$sql;
    }
}
?>

<?php
$sql = "SELECT* FROM teacher_profile";
$result = mysqli_query($conn, $sql);

if(mysqli_num_rows($result) > 0){
    echo "<table border = '1'> 
        <tr>
            <th>name</th>
            <th>subject</th>
            <th>email</th>
            <th>phone</th>
            <th>Action</th>
        </tr>";
    while($row = mysqli_fetch_assoc($result)){
        echo "<tr>
            <td>{$row["name"]}</td>
            <td>{$row["subject"]}</td>
            <td>{$row["email"]}</td>
            <td>{$row["phone"]}</td>
            <td><a href='edit.php ? id=".$row["phone"]."'>Edit</a></td>
            </tr>";
    }
    echo "</table>";
} else {
    echo "No products Found";
}
?>
<?php
// UPDATE on form submit
if ($_SERVER["REQUEST_METHOD"] === "POST" && isset($_POST["update"])) {
    $name = $_POST["name"];
    $subject = $_POST["sub"];
    $email = $_POST["email"];
    $phone = $_POST["phone"];

    $sql = "UPDATE teacher_profile SET 
            name='$name', subject='$subject', email='$email', phone='$phone' 
            WHERE id=$id";

    if (mysqli_query($conn, $sql)) {
        echo "Record updated successfully. <a href='submit.php'>Back to list</a>";
        exit;
    } else {
        echo "Update failed: " . mysqli_error($conn);
    }
}

// FETCH teacher by ID
if (isset($_GET['phone'])) {
    $phone = $_GET['phone'];
    $result = mysqli_query($conn, "SELECT * FROM teacher_profile WHERE phone = $phone");
    $row = mysqli_fetch_assoc($result);
} else {
    die("No teacher ID provided.");
}

mysqli_close($conn);
?>
