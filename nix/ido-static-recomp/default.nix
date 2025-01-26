{
  stdenv,
  fetchFromGitHub,
  gnumake,
  ido-version ? "7.1",
  release ? true,
}:
stdenv.mkDerivation (finalAttrs: {
  pname = "ido-static-recomp-${ido-version}";
  version = "v1.2";

  src = fetchFromGitHub {
    owner = "decompals";
    repo = "ido-static-recomp";
    rev = finalAttrs.version;
    sha256 = "sha256-E2lJi+SvRFObUyj3fgME1AIwEna390dnyU4B18cXe44=";
  };

  nativeBuildInputs = [gnumake];

  buildPhase = ''
    runHook preBuild
    make setup
    make VERSION=${ido-version} RELEASE=${
      if release
      then "1"
      else "0"
    }
    runHook postBuild
  '';

  installPhase = ''
    runHook preInstall
    mkdir -p $out/bin $out/share/ido-static-recomp
    find build/${ido-version}/out -name '*.cc' -exec cp -v {} $out/share/ido-static-recomp/ \;
    find build/${ido-version}/out -type f ! -name '*.cc' -exec cp -v {} $out/bin/ \;
    runHook postInstall
  '';
})
