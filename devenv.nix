{ pkgs, lib, config, inputs, ... }:

{
  # https://devenv.sh/packages/
  packages = [ 
    pkgs.bashInteractive
    pkgs.devenv
    pkgs.git
    pkgs.cmake
    pkgs.lua5_3
    pkgs.libmysqlclient
    pkgs.db
    pkgs.db.dev
    pkgs.temurin-bin
    pkgs.boost.dev
    pkgs.openssl.dev
    pkgs.zlib.dev
    pkgs.gtest
    pkgs.libgcc.lib
  ];

  # https://devenv.sh/languages/
  languages.cplusplus.enable = true;

  # https://devenv.sh/pre-commit-hooks/
  # pre-commit.hooks.shellcheck.enable = true;
}
