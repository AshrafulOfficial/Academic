<?php
$servername = "localhost";
$username = "root";
$password ="";
$dbname = "productdb";

$conn = mysqli_connect($servername, $username, $password, $dbname);
if(!$conn){
    die("Connection Failed: ".mysqli_connect_error());
}
if ($_SERVER["REQUEST_METHOD"] == "POST"){
    $name = $_POST['name']; 
    $category = $_POST['category'];
    $price = $_POST['price'];
    $brand = $_POST['brand'];
    $count = $_POST['count'];
    $color = $_POST['color'];
    
    $sql = "INSERT INTO product_table(name,category,price,brand,count,color)
    values('$name','$category','$price','brand','$count','$color')";

    if(mysqli_query($conn, $sql)){
    echo"New record Created Successfully.";
    }else{
    echo"Error: ".$sql;
    }
}
?>
<?php
$sql = "SELECT * FROM product_table";
$result = mysqli_query($conn, $sql);

if (mysqli_num_rows($result) > 0) {
    echo "<table border='1'>
        <tr>
            <th>name</th>
            <th>category</th>
            <th>price</th>
            <th>brand</th>
            <th>count</th>
            <th>color</th>
        </tr>";

    while ($row = mysqli_fetch_assoc($result)) {
        echo "<tr>
            <td>{$row['name']}</td>
            <td>{$row['category']}</td>
            <td>{$row['price']}</td>
            <td>{$row['brand']}</td>
            <td>{$row['count']}</td>
            <td>{$row['color']}</td>
        </tr>";
    }

    echo "</table>";
} else {
    echo "<p>No products found.</p>";
}

mysqli_close($conn);
?>

