
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title><?php echo $title; ?></title>
        <link rel="stylesheet" type="text/css" href="Styles/Stylesheet.css" />
    </head>
    <body>
        <div id="wrapper">
            <div id="banner">
        </div>
            <nav id="navigation">
                <ul id="nav">
                    <li><a href="index.php">Casa</a></li>
                    <li><a href="Coffee.php">Cafea</a></li>
                    <li><a href="Magazine.php">Magazine</a></li>
                    <li><a href="About.php">Despre</a></li>
                    <li><a href="Management.php">Management</a></li>
                </ul>
            </nav>
            <div id="content_area">
                <?php echo $content; ?>
            </div>
            <footer>
                
            </footer>
        </div>
    </body>
</html>
