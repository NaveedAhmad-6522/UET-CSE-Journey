<?php

return [

    'paths' => [
        'api/*',
        'sanctum/csrf-cookie',
        'students',
        'courses',
        'departments',
        'registrations',
        'schedules',
        'instructors',
        'classrooms',
    ],

    'allowed_methods' => ['*'],

    'allowed_origins' => [
    'http://localhost:3000',
    'https://courseregistrationsystemuet.netlify.app',
],

    'allowed_headers' => ['*'],

    'exposed_headers' => [],

    'max_age' => 0,

    'supports_credentials' => true,

];