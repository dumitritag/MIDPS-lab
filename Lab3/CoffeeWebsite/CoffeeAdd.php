<?php
require './Controller/CoffeeController.php';
$coffeeController = new CoffeeController();

$title = "Adauga o noua cafea";

$content ="<form action='' method='post'>
    <fieldset>
        <legend>Adauga o noua cafea</legend>
        <label for='name'>Nume: </label>
        <input type='text' class='inputField' name='txtName' /><br/>

        <label for='type'>Tip: </label>
        <select class='inputField' name='ddlType'>
            <option value='%'>Toate</option>"
        .$coffeeController->CreateOptionValues($coffeeController->GetCoffeeTypes()).
        "</select><br/>

        <label for='price'>Pret: </label>
        <input type='text' class='inputField' name='txtPrice' /><br/>

        <label for='roast'>Prajit: </label>
        <input type='text' class='inputField' name='txtRoast' /><br/>

        <label for='country'>Tara: </label>
        <input type='text' class='inputField' name='txtCountry' /><br/>
        

        <label for='image'>Imagine: </label>
        <select class='inputField' name='ddlImage'>"
        .$coffeeController->GetImages().
        "</select></br>

        <label for='review'>Descriere: </label>
        <textarea cols='70' rows='12' name='txtReview'></textarea></br>

        <input type='submit' value='Submit'>
    </fieldset>
</form>";


if(isset($_POST["txtName"]))
{
    $coffeeController->InsertCoffee();
}
include './Template.php';
?>

