<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://codex.wordpress.org/Editing_wp-config.php
 *
 * @package WordPress
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'root' );

/** MySQL database password */
define( 'DB_PASSWORD', '' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'd> hA+b8k?%8O/3Jk3fQo`eR|eu%g#_Sts0XPO4[4][W8>F7MOh4+Xc+]*wdDS2U');
define('SECURE_AUTH_KEY',  'JT%/TuzphZzlr>~N#(L}P!FmUMS?x[ix!Zr`Yh:/#C7<|(.h|3?zi[z=`9<+^-lc');
define('LOGGED_IN_KEY',    'jiSKZCB(L-V`|AS|}LxY0XeHw[;nNl<~Ui,0I**<zM$OrAronmgrtK?YeA9e+EpY');
define('NONCE_KEY',        'u`foYoE+mhvDa8xU]Y#51{z-$*9tgFCvN&ya/1P:$c|FCD$&sYl=EE4eQt- {]qg');
define('AUTH_SALT',        'J,sgR.#@S.,A[k_ube[(b}:(|?WOk7zzY-|6rhJd6:>Jr=r*~x(FgD)c|OPv5S}a');
define('SECURE_AUTH_SALT', 'q{`xptNi/2|3N+lXWhU>-?@F}C2d&$|=b+WcsjPYj?ODYJ#gNDYj}MLrIU5@n/v1');
define('LOGGED_IN_SALT',   ',Zp@Z_A1g8_02HWSKi[2:ucuV^)6-Mn@OK6FRqO7%nJq}XFD(63oD}B|+rQ$JtnJ');
define('NONCE_SALT',       'MQGO~spwd<3L5]g*vSYo=zg$y}ai -aiPEy8/@o$0kU%V![P[j!xlU[},9PHm`uP');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
        define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );