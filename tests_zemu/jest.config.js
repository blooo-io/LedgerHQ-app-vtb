module.exports = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  transformIgnorePatterns: ['^.+\\.js$'],
  testMatch: [
    "**/standard.test.ts",
  ],
}
