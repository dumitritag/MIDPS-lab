
<?php

require ("Model/CoffeeModel.php");

//Contains non-database related for the Coffee page
class CoffeeController {
    
    function CreateCoffeeDropdownList()
    { 
        $coffeeModel = new CoffeeModel();
        $result = "<form action = '' method  = 'post' width = '200px'>
            Alegeti tipul:
            <select name = 'types' >
            <option value = '%' >Toate</option>
            ".$this->CreateOptionValues($coffeeModel->GetCoffeeTypes()).
                "</select>
                    <input type = 'submit' value = 'Cautare' />
                    </form>";
        return  $result;
                
    }
    
    function CreateOptionValues(array $valueArray)
    { 
        $result = "";
        
        foreach ($valueArray as $value)
            { 
            $result = $result . "<option value='$value'>$value</option>";
            }
            return $result;
    }
    
    function CreateCoffeeTables($types)
    { 
        $coffeeModel = new CoffeeModel();
        $coffeeArray = $coffeeModel->GetCoffeeByType($types);
        $result = "";
        
        //Generate a coffeeTable for each coffyEntity in array
        foreach ($coffeeArray as $key => $coffee)
            { 
            $result = $result . 
                    "<table class = 'coffeeTable'>
                        <tr>
                        <th rowspan='6' width = '150px' ><img runat = 'server' src = '$coffee->image' /></th>
                        <th>Nume: </th>
                        <td>$coffee->name</td>
                        </tr>
                        
<tr>
                        <th>Tip: </th>
                        <td>$coffee->type</td>
                        </tr>
                        
<tr>
                        <th>Pret: </th>
                        <td>$coffee->price</td>
                        </tr>
                        
<tr>
                        <th>Prajit: </th>
                        <td>$coffee->roast</td>
                        </tr>
                        
<tr>
                        <th>Origine: </th>
                        <td>$coffee->country</td>
                        </tr>
                        
<tr>
<td colspan='2' >$coffee->review</td>
    </tr>
                        
</table>";
                    
            }
            return $result;
    }
    
    //Returns list of files in a folder.
    function GetImages() {
        //Select folder to scan
        $handle = opendir("Images/Coffee");

        //Read all files and store names in array
        while ($image = readdir($handle)) {
            $images[] = $image;
        }

        closedir($handle);

        //Exclude all filenames where filename length < 3
        $imageArray = array();
        foreach ($images as $image) {
            if (strlen($image) > 2) {
                array_push($imageArray, $image);
            }
        }

        //Create <select><option> Values and return result
        $result = $this->CreateOptionValues($imageArray);
        return $result;
    }

    //<editor-fold desc="Set Methods">
    function InsertCoffee() {
        $name = $_POST["txtName"];
        $type = $_POST["ddlType"];
        $price = $_POST["txtPrice"];
        $roast = $_POST["txtRoast"];
        $country = $_POST["txtCountry"];
        $image = $_POST["ddlImage"];
        $review = $_POST["txtReview"];

        $coffee = new CoffeeEntity(-1, $name, $type, $price, $roast, $country, $image, $review);
        $coffeeModel = new CoffeeModel();
        $coffeeModel->InsertCoffee($coffee);
    }

    function GetCoffeeById($id) {
        $coffeeModel = new CoffeeModel();
        return $coffeeModel->GetCoffeeById($id);
    }

    function GetCoffeeByType($type) {
        $coffeeModel = new CoffeeModel();
        return $coffeeModel->GetCoffeeByType($type);
    }

    function GetCoffeeTypes() {
        $coffeeModel = new CoffeeModel();
        return $coffeeModel->GetCoffeeTypes();
    }
    //</editor-fold>
}
?>